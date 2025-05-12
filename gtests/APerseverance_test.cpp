//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
// Use the corrected template for amulets with default constructor
#include "AmuletTemplateN.h"
#include "APerseverance.h"
#include "Player.h" // Include Player header for manipulating player health

// Define the test fixture using the template
typedef AmuletTest<APerseverance> APerseveranceTestFixture;

// Test Case 1: Initialization
TEST_F(APerseveranceTestFixture, Init)
{
    EXPECT_EQ(amulet->getCost(), 100);
    EXPECT_EQ(amulet->getName(), "perseverance");
    // Check the potentially long description string from the implementation
    EXPECT_EQ(amulet->getDescription(), "If you are on the verge of death, \nyou have a second chance! \nBut don't be intoxicated by this power... \nBecause you have only one usage! \nthen you need to pay 50 gold.");
    EXPECT_EQ(amulet->getSlots(), 5);
    EXPECT_EQ(amulet->getUsage(), false); // Base class usage flag
    EXPECT_EQ(amulet->getWasUsed(), false); // Perseverance specific flag
    EXPECT_EQ(amulet->getAdditionalHealth(), 100);
}

// Test Case 2: Use Cases for the Amulet
TEST_F(APerseveranceTestFixture, UsingEffect)
{
    // Scenario 1: Player health is high ( > 30 ) - amulet should not activate
    unsigned int hp = 50;
    player->setHealth(hp);
    unsigned int health_before_use1 = player->getHealth();
    amulet->use(*player);
    EXPECT_EQ(player->getHealth(), health_before_use1); // Health should not change
    EXPECT_FALSE(amulet->getWasUsed()); // Amulet should not be marked as used

    // Scenario 2: Player health is zero - amulet should not activate
    hp = 0;
    player->setHealth(hp);
    unsigned int health_before_use2 = player->getHealth();
    amulet->use(*player);
    EXPECT_EQ(player->getHealth(), health_before_use2); // Health should remain 0
    EXPECT_FALSE(amulet->getWasUsed()); // Amulet should not be marked as used

    // Scenario 3: Player health is low (e.g., 1 <= health <= 30) - amulet should activate
    hp = 15;
    player->setHealth(hp);
    amulet->use(*player);
    EXPECT_EQ(player->getHealth(), amulet->getAdditionalHealth()); // Health should be restored to additional_health (100)
    EXPECT_TRUE(amulet->getWasUsed()); // Amulet should be marked as used

    // Scenario 4: Try using again after activation - should not work
    hp = 20;
    player->setHealth(hp); // Set health low again
    unsigned int health_before_use4 = player->getHealth();
    amulet->use(*player);
    EXPECT_EQ(player->getHealth(), health_before_use4); // Health should not change
    EXPECT_TRUE(amulet->getWasUsed()); // Should still be marked as used
}

// Ensure old incorrect test class and methods are removed. 