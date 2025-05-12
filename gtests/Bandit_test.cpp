//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Bandit.h"
#include "Player.h"
#include "GameField.h" // Needed for move method
#include "YardDragon.h" // Needed for GameField initialization
#include <memory>

class BanditTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<Bandit> bandit;
    std::shared_ptr<YardDragon> dragon; // Changed from dummy_enemy to dragon to make it clearer
    std::shared_ptr<GameField> field; // Use smart pointer

    // Initial stats
    const std::string bandit_name = "TestBandit";
    const unsigned int initial_health = 70;
    const unsigned int initial_damage = 10;
    const unsigned int initial_iq = 10;
    const unsigned int initial_exp = 15;
    const unsigned int initial_player_exp = 5;
    const unsigned int initial_player_gold = 20;

    void SetUp() override {
        player = std::make_shared<Player>("TestPlayer");
        player->setExp(initial_player_exp);
        player->setGold(initial_player_gold);

        // Correct Bandit constructor
        bandit = std::make_shared<Bandit>(
            bandit_name, initial_health, initial_damage, initial_iq, initial_exp, player.get()
        );

        // Create proper YardDragon for GameField initialization
        dragon = std::make_shared<YardDragon>("TestDragon", 100, 20, 10, 50, player.get(), 3);
        
        // Initialize GameField with player and YardDragon as required
        field = std::make_shared<GameField>(*player, dragon);

        // Set initial positions for tests
        bandit->setX_pos(5);
        bandit->setY_pos(5);
        player->setX_pos(10);
        player->setY_pos(10);
        // Update field representation if needed by move()
        field->setSymbol(5, 5, 'b');
        field->setSymbol(10, 10, '@');
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(BanditTest, Init)
{
    // Check stats set in constructor (using getters from Fighter/Enemy)
    EXPECT_EQ(bandit->getName(), bandit_name);
    EXPECT_EQ(bandit->getHealth(), initial_health);
    EXPECT_EQ(bandit->getDamage(), initial_damage);
    EXPECT_EQ(bandit->getIQ(), initial_iq);
    EXPECT_EQ(bandit->getExp(), initial_exp);
}

TEST_F(BanditTest, PositionManagement)
{
    unsigned int new_x = 6;
    unsigned int new_y = 7;
    bandit->setX_pos(new_x);
    bandit->setY_pos(new_y);
    EXPECT_EQ(bandit->getX_pos(), new_x);
    EXPECT_EQ(bandit->getY_pos(), new_y);
}

TEST_F(BanditTest, TakeDamage)
{
    unsigned int damage_taken = 30;
    bandit->takeDamage(damage_taken);
    EXPECT_EQ(bandit->getHealth(), initial_health - damage_taken);

    // Take fatal damage
    bandit->takeDamage(initial_health); // Take exactly remaining health
    EXPECT_FALSE(bandit->isAlive());
    EXPECT_EQ(bandit->getHealth(), 0);
}

TEST_F(BanditTest, OnDeathRewards)
{
    // Assuming takeDamage does NOT automatically call onDeath.
    // We make the bandit take fatal damage, then call onDeath.
    bandit->takeDamage(initial_health + 10); // Ensure health is <= 0
    EXPECT_FALSE(bandit->isAlive());

    // Call onDeath explicitly to test its reward logic
    // implictly onDeath, because call in destructor of fighter
    EXPECT_EQ(player->getExp(), initial_player_exp + initial_exp);
    EXPECT_EQ(player->getGold(), initial_player_gold + initial_exp * 2);
}

// Simplified Movement Test (depends heavily on GameField assumptions)
TEST_F(BanditTest, MovementTowardsPlayer)
{
    int start_x = 5;
    int start_y = 5;
    bandit->setX_pos(start_x);
    bandit->setY_pos(start_y);
    player->setX_pos(10); // Player is to the SE
    player->setY_pos(10);

    // Clear potential obstacles around bandit in the assumed field
    field->setSymbol(start_x + 1, start_y, ' ');
    field->setSymbol(start_x, start_y + 1, ' ');
    field->setSymbol(start_x + 1, start_y + 1, ' ');
    field->setSymbol(start_x, start_y, 'b'); // Place bandit symbol
    field->setSymbol(10, 10, '@'); // Place player symbol


    bandit->move(*player, *field);

    // Bandit should move towards player. dist_x=5, dist_y=5.
    // Code logic: if (abs(dist_x) == abs(dist_y)) -> moves in x.
    int expected_x = start_x + 1; // Moves East
    int expected_y = start_y;
    EXPECT_EQ(bandit->getX_pos(), expected_x);
    EXPECT_EQ(bandit->getY_pos(), expected_y);
    // Also check if GameField symbol was updated (if move is supposed to do that)
    EXPECT_EQ(field->getSymbol(start_x, start_y), ' ');
    EXPECT_EQ(field->getSymbol(expected_x, expected_y), 'b');

    // --- Test movement primarily along Y --- 
    start_x = 5; start_y = 5;
    expected_y = start_y + 1; // Expect to move South
    expected_x = start_x;     // X should not change
    bandit->setX_pos(start_x);
    bandit->setY_pos(start_y);
    player->setX_pos(5); // Player is South
    player->setY_pos(10);
    field->setSymbol(start_x, start_y, 'b'); // Reset symbols
    field->setSymbol(5, 10, '@');
    field->setSymbol(start_x, start_y+1, ' '); // Clear path

    bandit->move(*player, *field);
    // dist_x = 0, dist_y = 5. abs(dist_x) < abs(dist_y) -> moves in y
    EXPECT_EQ(bandit->getX_pos(), expected_x);
    EXPECT_EQ(bandit->getY_pos(), expected_y);
    EXPECT_EQ(field->getSymbol(start_x, start_y), ' ');
    EXPECT_EQ(field->getSymbol(expected_x, expected_y), 'b');
}
