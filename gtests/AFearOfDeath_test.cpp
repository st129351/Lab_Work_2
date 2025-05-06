//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include "AmuletTemplateP.h"
#include "AFearOfDeath.h"

typedef AmuletTest<AFearOfDeath> FODTest;
TEST_F(FODTest, Initialization)
{
    EXPECT_EQ(amulet->getCost(), 35);
    EXPECT_EQ(amulet->getName(), "fear of death");
    EXPECT_EQ(amulet->getDescription(), "increase damage by 50%");
    EXPECT_EQ(amulet->getSlots(), 2);
    EXPECT_EQ(amulet->getUsage(), false);
}

TEST_F(FODTest, Using)
{
    unsigned int curr = player->getDamage();
    unsigned int add_dam = amulet->getAdditionalDamage();
    amulet->use(*player);
    EXPECT_EQ(add_dam, curr * 0.5);
    EXPECT_EQ(player->getDamage(), curr + add_dam);
}