//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
// Use the corrected template for amulets taking Player&
#include "AmuletTemplateP.h"
#include "AMadness.h"
#include "Player.h" // Include Player to get stats

// Define the test fixture using the template
typedef AmuletTest<AMadness> AMadnessTestFixture; // Renamed to avoid conflict with class name

// Test Case 1: Initialization
TEST_F(AMadnessTestFixture, Init)
{
    // Check base Amulet properties set in AMadness constructor
    EXPECT_EQ(amulet->getCost(), 50);
    EXPECT_EQ(amulet->getName(), "madness");
    EXPECT_EQ(amulet->getDescription(), "increase damage by 100%, but has side effect, be careful!");
    EXPECT_EQ(amulet->getSlots(), 3);
    EXPECT_EQ(amulet->getUsage(), false);

    // Check AMadness specific calculated properties
    unsigned int initial_player_damage = player->getDamage(); // Get actual initial damage from player object
    unsigned int initial_player_health = player->getHealth(); // Get actual initial health from player object
    EXPECT_EQ(amulet->getAdditionalDamage(), initial_player_damage * 1);
    EXPECT_EQ(amulet->getSideEffect(), initial_player_health * 0.5);
}

// Test Case 2: Using the Amulet
TEST_F(AMadnessTestFixture, UsingEffect)
{
    // Get initial player stats
    unsigned int initial_health = player->getHealth();
    unsigned int initial_damage = player->getDamage();

    // Get amulet effects calculated during initialization
    // Need to get these directly from the amulet instance
    unsigned int add_damage = amulet->getAdditionalDamage();
    unsigned int side_effect = amulet->getSideEffect();

    // Use the amulet
    amulet->use(*player);

    // Verify player stats changed correctly
    EXPECT_EQ(player->getDamage(), initial_damage + add_damage);
    EXPECT_EQ(player->getHealth(), initial_health - side_effect);
}

// Ensure old incorrect test class and methods are removed. 