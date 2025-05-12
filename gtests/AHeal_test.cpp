//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include "AmuletTemplateN.h"
#include "AHeal.h"

typedef AmuletTest<AHeal> Heal;
TEST_F(Heal, Init)
{
    EXPECT_EQ(amulet->getCost(), 15);
    EXPECT_EQ(amulet->getName(), "heal");
    EXPECT_EQ(amulet->getDescription(), "great healing power");
    EXPECT_EQ(amulet->getSlots(), 5);
    EXPECT_EQ(amulet->getUsage(), false);
}

TEST_F(Heal, Using)
{
    unsigned int curr = player->getHealth();
    unsigned int heal_value = amulet->getHealValue();
    unsigned int new_health = 50;
    amulet->use(*player);
    EXPECT_EQ(player->getHealth(), curr); // because default hp == 100 (max)
    player->setHealth(new_health);
    curr = player->getHealth();
    amulet->use(*player);
    EXPECT_EQ(player->getHealth(), curr + heal_value);
}