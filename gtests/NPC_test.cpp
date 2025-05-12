//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "NPC.h"
#include <memory>
#include <string>

class TestNPC : public NPC {
public:
    TestNPC(const std::string& name, const std::string& description)
        : NPC(name, description) {}

    void speak() override {
        setDialogueComplete(true);
    }
};

class NPCTest : public ::testing::Test {
protected:
    std::shared_ptr<TestNPC> npc;

    const std::string initial_name = "TestNPC";
    const std::string initial_description = "Test description for NPC";
    
    const int initial_x = 5;
    const int initial_y = 7;

    void SetUp() override {
        npc = std::make_shared<TestNPC>(initial_name, initial_description);
        npc->setX_pos(initial_x);
        npc->setY_pos(initial_y);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(NPCTest, Init)
{
    EXPECT_EQ(npc->getName(), initial_name);
    EXPECT_EQ(npc->getDescription(), initial_description);
    EXPECT_FALSE(npc->getDialogueComplete());
    
    EXPECT_EQ(npc->getX_pos(), initial_x);
    EXPECT_EQ(npc->getY_pos(), initial_y);
}

TEST_F(NPCTest, StrsManagement)
{
    std::string new_name = "NewNPC";
    std::string new_description = "New description";
    
    npc->setName(new_name);
    npc->setDescription(new_description);
    
    EXPECT_EQ(npc->getName(), new_name);
    EXPECT_EQ(npc->getDescription(), new_description);
}

TEST_F(NPCTest, PosManagement)
{
    int new_x = 10, new_y = 12;
    
    npc->setX_pos(new_x);
    npc->setY_pos(new_y);
    
    EXPECT_EQ(npc->getX_pos(), new_x);
    EXPECT_EQ(npc->getY_pos(), new_y);
}

TEST_F(NPCTest, DialogueCompleteFlag)
{
    EXPECT_FALSE(npc->getDialogueComplete());
    
    npc->setDialogueComplete(true);
    EXPECT_TRUE(npc->getDialogueComplete());
    
    npc->setDialogueComplete(false);
    EXPECT_FALSE(npc->getDialogueComplete());
}

TEST_F(NPCTest, Speak)
{
    EXPECT_FALSE(npc->getDialogueComplete());
    
    npc->speak();
    
    EXPECT_TRUE(npc->getDialogueComplete());
} 