//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include "AmuletTemplateF.h"
#include "ADash.h"

typedef AmuletTest<ADash> DashTest;
TEST_F(DashTest, Init) 
{
    EXPECT_EQ(amulet->getCost(), 25);
    EXPECT_EQ(amulet->getName(), "dash");
    EXPECT_EQ(amulet->getDescription(), "incredible speed, press 'k'");
    EXPECT_EQ(amulet->getSlots(), 8);
    EXPECT_EQ(amulet->getUsage(), false);
}

TEST_F(DashTest, amuletUp) 
{
    player->setX_pos(10);
    player->setY_pos(10);
    
    field->setInputSymb('w');
    
    // Выполняем рывок
    amulet->use(*player);
    
    EXPECT_EQ(player->getY_pos(), 8); 
    EXPECT_EQ(player->getX_pos(), 10); 
}

TEST_F(DashTest, amuletRight) 
{
    player->setX_pos(10);
    player->setY_pos(10);
    
    field->setInputSymb('d');
    amulet->use(*player);
    
    EXPECT_EQ(player->getX_pos(), 12);
    EXPECT_EQ(player->getY_pos(), 10);
}

TEST_F(DashTest, WallCollision) 
{
    player->setX_pos(10);
    player->setY_pos(10);
    
    field->setSymbol(10, 9, '#');
    
    field->setInputSymb('w');
    amulet->use(*player);
    
    EXPECT_EQ(player->getY_pos(), 10);
    EXPECT_EQ(player->getX_pos(), 10);
}

TEST_F(DashTest, VisualEffects) 
{
    player->setX_pos(10);
    player->setY_pos(10);
    
    field->setInputSymb('w');
    amulet->use(*player);
    
    EXPECT_EQ(field->getSymbol(10, 10), '|');
    EXPECT_EQ(field->getSymbol(10, 9), '|');
    
    amulet->UpdateDashVisual();
    EXPECT_EQ(field->getSymbol(10, 10), ' ');
    EXPECT_EQ(field->getSymbol(10, 9), ' ');
}


