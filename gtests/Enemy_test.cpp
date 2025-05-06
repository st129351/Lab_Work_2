//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Enemy.h"
#include "Player.h"
#include "GameField.h" // Needed for move signature
#include <memory>
#include <string>

// Minimal concrete derived class for testing Enemy's non-virtual functions
class TestEnemy : public Enemy {
public:
    // Use the base class constructor
    TestEnemy(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player)
        : Enemy(name, health, damage, iq, exp, player) {}

    // Provide implementations for pure virtual functions
    void move(Player& player, GameField& field) override {
        // Dummy implementation - behavior not tested here
    }
    void onDeath() override {
        // Dummy implementation - behavior not tested here
    }
};

class EnemyBaseTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<TestEnemy> test_enemy;
    // No GameField needed for these tests

    // Initial values
    const std::string initial_name = "TestEnemy";
    const unsigned int initial_health = 100;
    const unsigned int initial_damage = 10;
    const unsigned int initial_iq = 20;
    const unsigned int initial_exp = 50;

    void SetUp() override {
        player = std::make_shared<Player>("TestPlayerForEnemy");
        test_enemy = std::make_shared<TestEnemy>(
            initial_name, initial_health, initial_damage, initial_iq, initial_exp, player.get()
        );
        // Set initial position for testing pos getters/setters
        test_enemy->setX_pos(1);
        test_enemy->setY_pos(2);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(EnemyBaseTest, Init) {
    // Check values set by constructor (using getters from Enemy and Fighter)
    EXPECT_EQ(test_enemy->getName(), initial_name);
    EXPECT_EQ(test_enemy->getHealth(), initial_health);
    EXPECT_EQ(test_enemy->getDamage(), initial_damage);
    EXPECT_EQ(test_enemy->getIQ(), initial_iq);
    EXPECT_EQ(test_enemy->getExp(), initial_exp);
    EXPECT_EQ(test_enemy->getPlayer().getName(), player->getName()); // Check player pointer
    // Check initial position set in SetUp
    EXPECT_EQ(test_enemy->getX_pos(), 1);
    EXPECT_EQ(test_enemy->getY_pos(), 2);
}

TEST_F(EnemyBaseTest, GettersAndSetters) {
    // Test setters and getters for Enemy specific fields
    unsigned int new_iq = 25;
    unsigned int new_exp = 55;
    int new_x = 3;
    int new_y = 4;
    std::string new_desc = "New Desc";
    auto new_player = std::make_shared<Player>("NewPlayer");

    test_enemy->setIQ(new_iq);
    test_enemy->setExp(new_exp);
    test_enemy->setX_pos(new_x);
    test_enemy->setY_pos(new_y);
    test_enemy->setEnemyDescription(new_desc);
    test_enemy->setPlayer(new_player.get());

    EXPECT_EQ(test_enemy->getIQ(), new_iq);
    EXPECT_EQ(test_enemy->getExp(), new_exp);
    EXPECT_EQ(test_enemy->getX_pos(), new_x);
    EXPECT_EQ(test_enemy->getY_pos(), new_y);
    EXPECT_EQ(test_enemy->getEnemyDescription(), new_desc);
    EXPECT_EQ(test_enemy->getPlayer().getName(), new_player->getName());

    // Test setters/getters inherited from Fighter
    unsigned int new_health_val = 90;
    unsigned int new_damage_val = 15;
    std::string new_fighter_name = "NewFighterName";

    test_enemy->setHealth(new_health_val);
    test_enemy->setDamage(new_damage_val);
    test_enemy->setName(new_fighter_name);

    EXPECT_EQ(test_enemy->getHealth(), new_health_val);
    EXPECT_EQ(test_enemy->getDamage(), new_damage_val);
    EXPECT_EQ(test_enemy->getName(), new_fighter_name);
}

TEST_F(EnemyBaseTest, TakeDamageAndIsAlive) {
    EXPECT_TRUE(test_enemy->isAlive());
    EXPECT_EQ(test_enemy->getHealth(), initial_health);

    unsigned int damage1 = 30;
    test_enemy->takeDamage(damage1);
    EXPECT_TRUE(test_enemy->isAlive());
    EXPECT_EQ(test_enemy->getHealth(), initial_health - damage1);

    // Take fatal damage
    test_enemy->takeDamage(initial_health); // Damage > remaining health
    EXPECT_FALSE(test_enemy->isAlive());
    EXPECT_EQ(test_enemy->getHealth(), 0); // Should clamp at 0

     // Take damage when already dead
     test_enemy->takeDamage(10);
     EXPECT_FALSE(test_enemy->isAlive());
     EXPECT_EQ(test_enemy->getHealth(), 0); // Health should remain 0
}
