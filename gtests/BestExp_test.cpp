//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
// Use the corrected template for amulets taking Player&
#include "AmuletTemplateP.h"
#include "BestExp.h"
#include "Player.h" // Include Player to check exp

// Define the test fixture using the template
typedef AmuletTest<BestExp> BestExpTestFixture;

// Test Case 1: Initialization
TEST_F(BestExpTestFixture, Init)
{
    // Check base Amulet properties set in BestExp constructor
    EXPECT_EQ(amulet->getCost(), 15);
    EXPECT_EQ(amulet->getName(), "bestexp");
    EXPECT_EQ(amulet->getDescription(), "increases the experience at every step");
    EXPECT_EQ(amulet->getSlots(), 1);
    EXPECT_EQ(amulet->getUsage(), false);

    // Check BestExp specific properties
    EXPECT_EQ(amulet->getAddExp(), 1); // Initial value is 1
}

// Test Case 2: Using the Amulet
TEST_F(BestExpTestFixture, UsingEffect)
{
    // Get initial player exp
    unsigned int initial_exp = player->getExp();
    unsigned int add_exp = amulet->getAddExp();

    // Use the amulet
    amulet->use(*player);

    // Verify player exp increased
    EXPECT_EQ(player->getExp(), initial_exp + add_exp);

    // Use again
    amulet->use(*player);
    EXPECT_EQ(player->getExp(), initial_exp + add_exp + add_exp);
}

// Test setting add_exp (if needed, though setter is simple)
TEST_F(BestExpTestFixture, SetAddExp)
{
    unsigned int new_add_exp = 5;
    amulet->setAddExp(new_add_exp);
    EXPECT_EQ(amulet->getAddExp(), new_add_exp);

    // Verify use with new value
    unsigned int initial_exp = player->getExp();
    amulet->use(*player);
    EXPECT_EQ(player->getExp(), initial_exp + new_add_exp);
}

// Ensure old incorrect test class and methods are removed. 