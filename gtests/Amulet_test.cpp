//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Amulet.h"
#include "Player.h"
#include <memory>
#include <string>

// Minimal concrete derived class for testing Amulet's non-virtual functions
class TestAmulet : public Amulet {
public:
    // Use the base class constructor
    TestAmulet(unsigned int cost, bool usage, std::string name, std::string description, unsigned int slots)
        : Amulet(cost, usage, name, description, slots) {}

    // Provide implementation for the pure virtual function
    void use(Player& player) override {
        // Dummy implementation - behavior not tested here
        setUsage(true); // Example behavior
    }
};

class AmuletBaseTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<TestAmulet> test_amulet;

    // Initial values for testing setters/getters
    const unsigned int initial_cost = 10;
    const bool initial_usage = false;
    const std::string initial_name = "Test Name";
    const std::string initial_description = "Test Desc";
    const unsigned int initial_slots = 1;

    void SetUp() override {
        player = std::make_shared<Player>("TestPlayerForAmulet");
        test_amulet = std::make_shared<TestAmulet>(
            initial_cost,
            initial_usage,
            initial_name,
            initial_description,
            initial_slots
        );
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

// Test getters and setters inherited from Amulet
TEST_F(AmuletBaseTest, GetAndSet)
{
    // Check initial values using getters
    EXPECT_EQ(test_amulet->getCost(), initial_cost);
    EXPECT_EQ(test_amulet->getUsage(), initial_usage);
    EXPECT_EQ(test_amulet->getName(), initial_name);
    EXPECT_EQ(test_amulet->getDescription(), initial_description);
    EXPECT_EQ(test_amulet->getSlots(), initial_slots);

    // Modify values using setters
    unsigned int new_cost = 20;
    bool new_usage = true;
    std::string new_name = "New Name";
    std::string new_description = "New Desc";
    unsigned int new_slots = 2;

    test_amulet->setCost(new_cost);
    test_amulet->setUsage(new_usage);
    test_amulet->setName(new_name);
    test_amulet->setDescription(new_description);
    test_amulet->setSlots(new_slots);

    // Check new values using getters
    EXPECT_EQ(test_amulet->getCost(), new_cost);
    EXPECT_EQ(test_amulet->getUsage(), new_usage);
    EXPECT_EQ(test_amulet->getName(), new_name);
    EXPECT_EQ(test_amulet->getDescription(), new_description);
    EXPECT_EQ(test_amulet->getSlots(), new_slots);
}

// Test the dummy 'use' method (optional, just to ensure it runs)
TEST_F(AmuletBaseTest, UseCall)
{
    EXPECT_FALSE(test_amulet->getUsage()); // Initial state
    test_amulet->use(*player);
    EXPECT_TRUE(test_amulet->getUsage()); // State after dummy use
}