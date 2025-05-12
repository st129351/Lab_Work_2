//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Game.h"
#include "Player.h"
#include "GameField.h"
#include "YardDragon.h"
#include <memory>

class GameTest : public ::testing::Test 
{
protected:
    std::unique_ptr<Player> player;
    std::unique_ptr<Game> game;

    void SetUp() override {
        player = std::make_unique<Player>("TestPlayer");
        game = std::make_unique<Game>(*player);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(GameTest, Init)
{
    EXPECT_NE(game.get(), nullptr);
    
    EXPECT_EQ(player->getName(), "TestPlayer");
}

TEST_F(GameTest, TermModes)
{
    EXPECT_NO_THROW({
        game->enableRawMode();
        game->disableRawMode();
    });
}

TEST_F(GameTest, MultiInit)
{
    for (int i = 0; i < 5; i++) {
        game.reset(new Game(*player));
        EXPECT_NE(game.get(), nullptr);
    }
}