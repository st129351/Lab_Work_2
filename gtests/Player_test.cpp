//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Player.h"
#include "GameField.h"
#include "YardDragon.h"
#include "Enemy.h"
#include <memory>
#include <string>
#include <vector>

class PlayerTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<YardDragon> dragon;
    std::shared_ptr<GameField> field;

    const std::string player_name = "TestPlayer";
    const unsigned int initial_health = 100;
    const unsigned int initial_damage = 10;
    const unsigned int initial_gold = 100;
    const unsigned int expected_x_pos = 14;
    const unsigned int expected_y_pos = 13;

    void SetUp() override {
        player = std::make_shared<Player>(player_name);
        dragon = std::make_shared<YardDragon>("TestDragon", 100, 20, 10, 30, player.get(), 3);
        field = std::make_shared<GameField>(*player, dragon);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(PlayerTest, Init)
{
    EXPECT_EQ(player->getHealth(), initial_health);
    EXPECT_EQ(player->getDamage(), initial_damage);
    EXPECT_EQ(player->getX_pos(), expected_x_pos);
    EXPECT_EQ(player->getY_pos(), expected_y_pos);
    EXPECT_EQ(player->getName(), player_name);
    EXPECT_EQ(player->getLevel(), 1);
    EXPECT_EQ(player->getExp(), 0);
    EXPECT_EQ(player->getGold(), initial_gold);
    EXPECT_EQ(player->getMaxLevel(), 3);
}

TEST_F(PlayerTest, LevelUp)
{
    unsigned int initial_level = player->getLevel();
    unsigned int initial_damage = player->getDamage();
    unsigned int initial_gold = player->getGold();
    unsigned int initial_health = player->getHealth();
    
    player->levelUp();
    
    EXPECT_EQ(player->getLevel(), initial_level + 1);
    EXPECT_EQ(player->getExp(), 0);
    EXPECT_GT(player->getGold(), initial_gold);
    EXPECT_GT(player->getDamage(), initial_damage); 
    EXPECT_GT(player->getHealth(), initial_health);
}

TEST_F(PlayerTest, PosManage)
{
    unsigned int new_x = 10, new_y = 15;
    player->setX_pos(new_x);
    player->setY_pos(new_y);
    EXPECT_EQ(player->getX_pos(), new_x);
    EXPECT_EQ(player->getY_pos(), new_y);
}

TEST_F(PlayerTest, ResourceManage)
{
    unsigned int new_exp = 50;
    unsigned int new_gold = 200;
    
    player->setExp(new_exp);
    player->setGold(new_gold);
    
    EXPECT_EQ(player->getExp(), new_exp);
    EXPECT_EQ(player->getGold(), new_gold);
}

TEST_F(PlayerTest, TakeDamage)
{
    unsigned int damage = 30;
    player->takeDamage(damage);
    EXPECT_EQ(player->getHealth(), initial_health - damage);
    
    player->takeDamage(initial_health);
    EXPECT_FALSE(player->isAlive());
    EXPECT_EQ(player->getHealth(), 0);
}

TEST_F(PlayerTest, AmuletFlags)
{
    EXPECT_FALSE(player->getPersevFlag());
    EXPECT_FALSE(player->getBestExpFlag());
    EXPECT_FALSE(player->getHealFlag());
    EXPECT_FALSE(player->getDashFlag());
    
    EXPECT_EQ(player->getPersev(), nullptr);
    EXPECT_EQ(player->getBestExp(), nullptr);
    EXPECT_EQ(player->getHeal(), nullptr);
    EXPECT_EQ(player->getDash(), nullptr);
    EXPECT_EQ(player->getKillerLook(), nullptr);
    EXPECT_EQ(player->getMadness(), nullptr);
    EXPECT_EQ(player->getFearOfDeath(), nullptr);
}

TEST_F(PlayerTest, AttackArea)
{
    std::vector<std::shared_ptr<Enemy>> enemies;
    enemies.push_back(dragon);
    
    dragon->setX_pos(player->getX_pos() + 1);
    dragon->setY_pos(player->getY_pos());
    
    field->setSymbol(dragon->getX_pos(), dragon->getY_pos(), 'Y');
    
    unsigned int initial_dragon_health = dragon->getHealth();
    
    player->attackArea(*field, enemies);
    
    if (abs(dragon->getX_pos() - player->getX_pos()) <= 1 && 
        abs(dragon->getY_pos() - player->getY_pos()) <= 1) {
        EXPECT_LT(dragon->getHealth(), initial_dragon_health);
    }
}

TEST_F(PlayerTest, Inventory)
{
    std::string inventory = player->showInventory();
    
    EXPECT_FALSE(inventory.empty());
    EXPECT_NE(inventory.find("Cells"), std::string::npos);
}

TEST_F(PlayerTest, OnDeath)
{
    player->onDeath();
    
    EXPECT_FALSE(player->isAlive());
    EXPECT_EQ(player->getHealth(), 0);
} 