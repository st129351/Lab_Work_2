//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Slime.h"
#include "Player.h"
#include "GameField.h"
#include "YardDragon.h"
#include <memory>

class SlimeTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<Slime> slime;
    std::shared_ptr<GameField> field;
    std::shared_ptr<YardDragon> dragon;

    // Параметры слайма для тестов
    const std::string slime_name = "TestSlime";
    const unsigned int initial_health = 50;
    const unsigned int initial_damage = 5;
    const unsigned int initial_iq = 5;
    const unsigned int initial_exp = 15;
    const unsigned int initial_poison_damage = 3;

    void SetUp() override {
        player = std::make_shared<Player>("TestPlayer");
        player->setX_pos(10);
        player->setY_pos(10);
        
        dragon = std::make_shared<YardDragon>("TestDragon", 100, 20, 10, 50, player.get(), 3);
        
        slime = std::make_shared<Slime>(
            slime_name, initial_health, initial_damage, initial_iq, initial_exp, 
            player.get(), initial_poison_damage
        );
        
        field = std::make_shared<GameField>(*player, dragon);
        
        slime->setX_pos(5);
        slime->setY_pos(5);
        field->setSymbol(5, 5, 's');
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(SlimeTest, Init)
{
    EXPECT_EQ(slime->getName(), slime_name);
    EXPECT_EQ(slime->getHealth(), initial_health);
    EXPECT_EQ(slime->getDamage(), initial_damage);
    EXPECT_EQ(slime->getIQ(), initial_iq);
    EXPECT_EQ(slime->getExp(), initial_exp);
    
    EXPECT_EQ(slime->getPoisonDamage(), initial_poison_damage);
}

TEST_F(SlimeTest, PosnManage)
{
    slime->setX_pos(3);
    slime->setY_pos(3);
    EXPECT_EQ(slime->getX_pos(), 3);
    EXPECT_EQ(slime->getY_pos(), 3);
}

TEST_F(SlimeTest, PoisonDamageManage)
{
    unsigned int new_poison_damage = 7;
    slime->setPoisonDamage(new_poison_damage);
    EXPECT_EQ(slime->getPoisonDamage(), new_poison_damage);
}

TEST_F(SlimeTest, Movement)
{
    int initial_x = slime->getX_pos();
    int initial_y = slime->getY_pos();
    
    slime->move(*player, *field);
    
    EXPECT_EQ(slime->getX_pos(), initial_x + 1);
    EXPECT_EQ(slime->getY_pos(), initial_y);
    
    EXPECT_EQ(field->getSymbol(initial_x, initial_y), ' ');
    EXPECT_EQ(field->getSymbol(initial_x + 1, initial_y), 's');
}

TEST_F(SlimeTest, MoveByWall)
{
    int wall_x = slime->getX_pos() + 1;
    int wall_y = slime->getY_pos();
    field->setSymbol(wall_x, wall_y, '#');
    
    int initial_x = slime->getX_pos();
    int initial_y = slime->getY_pos();
    
    slime->move(*player, *field);
    
    EXPECT_EQ(slime->getX_pos(), initial_x);
    EXPECT_EQ(slime->getY_pos(), initial_y);
}

TEST_F(SlimeTest, TakeDamage)
{
    unsigned int damage = 20;
    slime->takeDamage(damage);
    EXPECT_EQ(slime->getHealth(), initial_health - damage);
    
    EXPECT_TRUE(slime->isAlive());
    
    slime->takeDamage(initial_health);
    EXPECT_EQ(slime->getHealth(), 0);
    EXPECT_FALSE(slime->isAlive());
}

TEST_F(SlimeTest, ApplyPoison)
{
    unsigned int initial_player_health = player->getHealth();
    
    slime->applyPoison(*player);
    
    EXPECT_EQ(player->getHealth(), initial_player_health - slime->getPoisonDamage());
    
    unsigned int current_player_health = player->getHealth();
    slime->applyPoison(*player);
    
    EXPECT_EQ(player->getHealth(), current_player_health - slime->getPoisonDamage());
}

TEST_F(SlimeTest, OnDeath)
{
    unsigned int initial_player_exp = player->getExp();
    unsigned int initial_player_gold = player->getGold();

    slime->takeDamage(initial_health);
    EXPECT_FALSE(slime->isAlive());

    EXPECT_EQ(player->getExp(), initial_player_exp + slime->getExp());
    EXPECT_EQ(player->getGold(), initial_player_gold + slime->getExp() * 2);
} 