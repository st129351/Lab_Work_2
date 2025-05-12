//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "GameField.h"
#include "Player.h"
#include "YardDragon.h"
#include "Elder.h"
#include "Trader.h"
#include "Slime.h"
#include "Bandit.h"
#include <memory>
#include <vector>

class GameFieldTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<YardDragon> dragon; // Needs to be shared_ptr for GameField constructor
    std::shared_ptr<GameField> field;

    int initial_player_x = 15; // Center X
    int initial_player_y = 7;  // Center Y

    void SetUp() override {
        // Player needs initial position before GameField uses it
        player = std::make_shared<Player>("TestPlayer");
        player->setX_pos(initial_player_x);
        player->setY_pos(initial_player_y);

        // YardDragon constructor needs Player*
        // Assuming YardDragon(name, health, damage, iq, exp, Player* player, range)
        dragon = std::make_shared<YardDragon>("TestDragon", 100, 20, 10, 50, player.get(), 3);

        // GameField constructor takes Player& and shared_ptr<YardDragon>&
        field = std::make_shared<GameField>(*player, dragon);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(GameFieldTest, Init) {
    // Check boundaries
    EXPECT_EQ(field->getSymbol(0, 0), '#');
    EXPECT_EQ(field->getSymbol(29, 0), '#');
    EXPECT_EQ(field->getSymbol(0, 14), '#');
    EXPECT_EQ(field->getSymbol(29, 14), '#');
    EXPECT_EQ(field->getSymbol(5, 0), '#');
    EXPECT_EQ(field->getSymbol(5, 14), '#');
    EXPECT_EQ(field->getSymbol(0, 5), '#');
    EXPECT_EQ(field->getSymbol(29, 5), '#');

    // Check inside is empty initially (except player)
    EXPECT_EQ(field->getSymbol(1, 1), ' ');
    EXPECT_EQ(field->getSymbol(28, 13), ' ');

    // Check player spawn position
    EXPECT_EQ(field->getSymbol(initial_player_x, initial_player_y), '@');

    // Check initial state variables
    EXPECT_FALSE(field->getPWasSeenD());
    EXPECT_EQ(field->getInputSymb(), 'w'); // Default input symbol
    EXPECT_EQ(field->getElder(), nullptr);
}

TEST_F(GameFieldTest, GetSetSymbol) {
    int x = 5, y = 6;
    char initial_symbol = field->getSymbol(x, y);
    EXPECT_EQ(initial_symbol, ' '); // Should be empty initially

    field->setSymbol(x, y, 'X');
    EXPECT_EQ(field->getSymbol(x, y), 'X');

    // Test boundaries
    field->setSymbol(-1, y, 'Z');
    EXPECT_NE(field->getSymbol(-1, y), 'Z'); // Should not set outside bounds
    field->setSymbol(30, y, 'Z');
    EXPECT_NE(field->getSymbol(30, y), 'Z');
    field->setSymbol(x, -1, 'Z');
    EXPECT_NE(field->getSymbol(x, -1), 'Z');
    field->setSymbol(x, 15, 'Z');
    EXPECT_NE(field->getSymbol(x, 15), 'Z');

    // Test getting outside bounds returns space (as per implementation)
    EXPECT_EQ(field->getSymbol(-1, y), ' ');
    EXPECT_EQ(field->getSymbol(30, y), ' ');
    EXPECT_EQ(field->getSymbol(x, -1), ' ');
    EXPECT_EQ(field->getSymbol(x, 15), ' ');
}

TEST_F(GameFieldTest, PlayerMovement) {
    int current_x = player->getX_pos();
    int current_y = player->getY_pos();

    // Move Up (w)
    field->Movement('w');
    EXPECT_EQ(player->getY_pos(), current_y - 1);
    EXPECT_EQ(player->getX_pos(), current_x);
    EXPECT_EQ(field->getSymbol(current_x, current_y), ' '); // Old position should be empty
    EXPECT_EQ(field->getSymbol(current_x, current_y - 1), '@'); // New position has player

    // Move Left (a)
    current_y = player->getY_pos(); // Update current_y
    field->Movement('a');
    EXPECT_EQ(player->getX_pos(), current_x - 1);
    EXPECT_EQ(player->getY_pos(), current_y);
    EXPECT_EQ(field->getSymbol(current_x, current_y), ' ');
    EXPECT_EQ(field->getSymbol(current_x - 1, current_y), '@');

    // Move Down (s)
    current_x = player->getX_pos(); // Update current_x
    field->Movement('s');
    EXPECT_EQ(player->getY_pos(), current_y + 1);
    EXPECT_EQ(player->getX_pos(), current_x);
    EXPECT_EQ(field->getSymbol(current_x, current_y), ' ');
    EXPECT_EQ(field->getSymbol(current_x, current_y + 1), '@');

    // Move Right (d)
    current_y = player->getY_pos(); // Update current_y
    field->Movement('d');
    EXPECT_EQ(player->getX_pos(), current_x + 1);
    EXPECT_EQ(player->getY_pos(), current_y);
    EXPECT_EQ(field->getSymbol(current_x, current_y), ' ');
    EXPECT_EQ(field->getSymbol(current_x + 1, current_y), '@');
}

TEST_F(GameFieldTest, PlayerMovementCollisionWall) {
    // Move player next to left wall
    player->setX_pos(1);
    player->setY_pos(5);
    field->setSymbol(1, 5, '@');
    field->setSymbol(2, 5, ' '); // Clear previous spot just in case

    int current_x = player->getX_pos();
    int current_y = player->getY_pos();

    // Try move Left (a) into wall
    field->Movement('a');
    EXPECT_EQ(player->getX_pos(), current_x); // Position should not change
    EXPECT_EQ(player->getY_pos(), current_y);
    EXPECT_EQ(field->getSymbol(current_x, current_y), '@'); // Player still there
    EXPECT_EQ(field->getSymbol(0, 5), '#'); // Wall is still there
}

TEST_F(GameFieldTest, Spawners) {
    // Test Elder Spawn
    int elder_x = 3, elder_y = 3;
    field->elderSpawn(elder_x, elder_y);
    EXPECT_EQ(field->getSymbol(elder_x, elder_y), 'E');
    ASSERT_NE(field->getElder(), nullptr);
    EXPECT_EQ(field->getElder()->getX_pos(), elder_x);
    EXPECT_EQ(field->getElder()->getY_pos(), elder_y);
    ASSERT_EQ(field->getNPC().size(), 1);
    EXPECT_EQ(field->getNPC()[0]->getName(), "Elder");

    // Test Trader Spawn
    int trader_x = 4, trader_y = 4;
    field->traderSpawn(trader_x, trader_y);
    EXPECT_EQ(field->getSymbol(trader_x, trader_y), 'T');
    ASSERT_EQ(field->getNPC().size(), 2);
    EXPECT_EQ(field->getNPC()[1]->getName(), "Trader");

    // Test Slime Spawn
    int slime_x = 5, slime_y = 5;
    field->slimeSpawn(slime_x, slime_y);
    EXPECT_EQ(field->getSymbol(slime_x, slime_y), 's');
    ASSERT_EQ(field->getEnemies().size(), 1);
    EXPECT_EQ(field->getEnemies()[0]->getName(), "Slime");

    // Test Bandit Spawn
    int bandit_x = 6, bandit_y = 6;
    field->banditSpawn(bandit_x, bandit_y);
    EXPECT_EQ(field->getSymbol(bandit_x, bandit_y), 'b');
    ASSERT_EQ(field->getEnemies().size(), 2);
    EXPECT_EQ(field->getEnemies()[1]->getName(), "Bandit");

     // Test YardDragon Spawn (uses the one passed in constructor initially)
     int dragon_x = 7, dragon_y = 7;
     field->yardDragonSpawn(dragon_x, dragon_y); // Should add the existing dragon to enemies vector
     EXPECT_EQ(field->getSymbol(dragon_x, dragon_y), 'Y');
     ASSERT_EQ(field->getEnemies().size(), 3);
     EXPECT_EQ(field->getEnemies()[2]->getName(), "TestDragon");
}

TEST_F(GameFieldTest, CheckCollision) {
    int target_x = 5, target_y = 5;
    // Player at (15, 7) initially
    EXPECT_FALSE(field->checkCollision(target_x, target_y));

    // Move player adjacent
    player->setX_pos(target_x + 1);
    player->setY_pos(target_y);
    EXPECT_TRUE(field->checkCollision(target_x, target_y));

    player->setX_pos(target_x - 1);
    player->setY_pos(target_y);
    EXPECT_TRUE(field->checkCollision(target_x, target_y));

    player->setX_pos(target_x);
    player->setY_pos(target_y + 1);
    EXPECT_TRUE(field->checkCollision(target_x, target_y));

    player->setX_pos(target_x);
    player->setY_pos(target_y - 1);
    EXPECT_TRUE(field->checkCollision(target_x, target_y));

    player->setX_pos(target_x + 1);
    player->setY_pos(target_y + 1);
    EXPECT_TRUE(field->checkCollision(target_x, target_y));

    // Move player away
    player->setX_pos(target_x + 2);
    player->setY_pos(target_y);
    EXPECT_FALSE(field->checkCollision(target_x, target_y));
}

TEST_F(GameFieldTest, CheckDragonRange) 
{
    int dragon_x = 10, dragon_y = 10;
    player->setX_pos(10);
    player->setY_pos(10);

    EXPECT_TRUE(field->checkDragonRange(dragon_x, dragon_y));
    
    player->setX_pos(13);
    player->setY_pos(12);

    EXPECT_TRUE(field->checkDragonRange(dragon_x, dragon_y));

    player->setX_pos(15);
    player->setY_pos(15);

    EXPECT_FALSE(field->checkDragonRange(dragon_x, dragon_y));
}
