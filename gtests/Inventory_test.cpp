//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Inventory.h"
#include "Player.h"
#include "Amulet.h"
#include <memory>
#include <string>

// Dummy Amulet class for testing purposes
// In a real scenario, you might use mocks or actual amulet implementations
class TestAmulet : public Amulet {
public:
    TestAmulet(const std::string& name, unsigned int slots)
        : Amulet(0, false, name, "Test Description", slots) {} // cost, usage, name, description, slots

    void use(Player& player) override {
        // Minimal implementation for testing Inventory
        // We might set usage to true or interact with player minimally if needed
        // For now, just setting usage to true to simulate activation
        setUsage(true);
    }
};

class InventoryTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<Inventory> inventory;

    void SetUp() override {
        player = std::make_shared<Player>("TestPlayer");
        inventory = std::make_shared<Inventory>(*player);
    }

    void TearDown() override {
    }
};

TEST_F(InventoryTest, Init)
{
    EXPECT_NE(inventory, nullptr);
    std::string initialShow = inventory->show();
    EXPECT_NE(initialShow.find("Size: 0/25"), std::string::npos);
    EXPECT_EQ(initialShow.find("TestAmulet1"), std::string::npos);
}

TEST_F(InventoryTest, AddItemSuccess)
{
    auto amulet1 = std::make_shared<TestAmulet>("TestAmulet1", 5);
    inventory->add(amulet1);
    std::string showOutput = inventory->show();
    EXPECT_NE(showOutput.find("Size: 5/25"), std::string::npos);
    EXPECT_NE(showOutput.find("TestAmulet1"), std::string::npos);
}

TEST_F(InventoryTest, AddItemFailWhenFull)
{
    auto amulet_big = std::make_shared<TestAmulet>("BigAmulet", 20);
    inventory->add(amulet_big);

    auto amulet_medium = std::make_shared<TestAmulet>("MediumAmulet", 5);
    inventory->add(amulet_medium);

    std::string showBeforeAdd = inventory->show();
    EXPECT_NE(showBeforeAdd.find("Size: 25/25"), std::string::npos);

    auto amulet_small = std::make_shared<TestAmulet>("SmallAmulet", 1);
    inventory->add(amulet_small);

    std::string showAfterAdd = inventory->show();
    EXPECT_NE(showAfterAdd.find("Size: 25/25"), std::string::npos);
    EXPECT_EQ(showAfterAdd.find("SmallAmulet"), std::string::npos);
    EXPECT_NE(showAfterAdd.find("BigAmulet"), std::string::npos);
    EXPECT_NE(showAfterAdd.find("MediumAmulet"), std::string::npos);
}

TEST_F(InventoryTest, AddItemFailExceedSlots)
{
    auto amulet_large = std::make_shared<TestAmulet>("TooLargeAmulet", 30);
    inventory->add(amulet_large);

    std::string showOutput = inventory->show();
    EXPECT_NE(showOutput.find("Size: 0/25"), std::string::npos);
    EXPECT_EQ(showOutput.find("TooLargeAmulet"), std::string::npos);
}

TEST_F(InventoryTest, ShowOutputFormat)
{
    auto amulet1 = std::make_shared<TestAmulet>("AmuletOne", 2);
    auto amulet2 = std::make_shared<TestAmulet>("AmuletTwo", 3);
    inventory->add(amulet1);
    inventory->add(amulet2);

    std::string showOutput = inventory->show();

    EXPECT_NE(showOutput.find("Size: 5/25"), std::string::npos);
    EXPECT_NE(showOutput.find("--------------------------------"), std::string::npos);
    EXPECT_NE(showOutput.find("AmuletOne"), std::string::npos);
    EXPECT_NE(showOutput.find("Description: Test Description"), std::string::npos);
    EXPECT_NE(showOutput.find("The 'AmuletOne' is off"), std::string::npos);
    EXPECT_NE(showOutput.find("AmuletTwo"), std::string::npos);
    EXPECT_NE(showOutput.find("The 'AmuletTwo' is off"), std::string::npos);
} 