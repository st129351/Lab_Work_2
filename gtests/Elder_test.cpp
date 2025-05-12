//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Elder.h"
#include <memory>

// No Player or GameField needed for these tests

class ElderTest : public ::testing::Test {
protected:
    std::shared_ptr<Elder> elder;

    void SetUp() override {
        elder = std::make_shared<Elder>(); // Elder has a default constructor
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(ElderTest, Init)
{
    // Check base NPC properties set by Elder's constructor
    EXPECT_EQ(elder->getName(), "Elder");
    EXPECT_EQ(elder->getDescription(), "The Elder of ancient village.");
    EXPECT_FALSE(elder->getDialogueComplete()); // Initial state from NPC constructor

    // Check Elder specific initial mission states
    EXPECT_TRUE(elder->getMission1());
    EXPECT_FALSE(elder->getMission2());
    EXPECT_FALSE(elder->getMission3());
}

TEST_F(ElderTest, MissionGettersSetters)
{
    // Test initial states again (redundant but ok)
    EXPECT_TRUE(elder->getMission1());
    EXPECT_FALSE(elder->getMission2());
    EXPECT_FALSE(elder->getMission3());

    // Test setters
    elder->setMission1(false);
    elder->setMission2(true);
    elder->setMission3(true);

    // Verify changes with getters
    EXPECT_FALSE(elder->getMission1());
    EXPECT_TRUE(elder->getMission2());
    EXPECT_TRUE(elder->getMission3());

    // Reset for other tests if needed (though SetUp does this)
    elder->setMission1(true);
    elder->setMission2(false);
    elder->setMission3(false);
}

TEST_F(ElderTest, SpeakLogicMission1)
{
    // Initial state: mission1=true, others false
    ASSERT_TRUE(elder->getMission1());
    ASSERT_FALSE(elder->getMission2());
    ASSERT_FALSE(elder->getMission3());
    elder->setDialogueComplete(false); // Ensure dialogue is not complete beforehand

    elder->speak(); // Call speak

    // Check state changes after speak when mission1 was true
    EXPECT_FALSE(elder->getMission1()); // mission1 should become false
    EXPECT_FALSE(elder->getMission2()); // mission2 should remain false
    EXPECT_FALSE(elder->getMission3()); // mission3 should remain false
    EXPECT_TRUE(elder->getDialogueComplete()); // dialogue should be marked complete
}

TEST_F(ElderTest, SpeakLogicMission2)
{
    // Setup state: mission1=false, mission2=true, mission3=false
    elder->setMission1(false);
    elder->setMission2(true);
    elder->setMission3(false);
    elder->setDialogueComplete(false);

    elder->speak(); // Call speak

    // Check state changes
    EXPECT_FALSE(elder->getMission1());
    EXPECT_FALSE(elder->getMission2()); // mission2 should become false
    EXPECT_FALSE(elder->getMission3());
    EXPECT_TRUE(elder->getDialogueComplete());
}

TEST_F(ElderTest, SpeakLogicMission3)
{
    // Setup state: mission1=false, mission2=false, mission3=true
    elder->setMission1(false);
    elder->setMission2(false);
    elder->setMission3(true);
    elder->setDialogueComplete(false);

    elder->speak(); // Call speak

    // Check state changes
    EXPECT_FALSE(elder->getMission1());
    EXPECT_FALSE(elder->getMission2());
    EXPECT_FALSE(elder->getMission3()); // mission3 should become false
    EXPECT_TRUE(elder->getDialogueComplete());
}

TEST_F(ElderTest, SpeakLogicAllMissionsDone)
{
    // Setup state: all missions false
    elder->setMission1(false);
    elder->setMission2(false);
    elder->setMission3(false);
    elder->setDialogueComplete(false);

    elder->speak(); // Call speak

    // Check state changes (enters the 'else' block)
    EXPECT_FALSE(elder->getMission1());
    EXPECT_FALSE(elder->getMission2());
    EXPECT_TRUE(elder->getMission3()); // mission3 should become true in the else block
    EXPECT_TRUE(elder->getDialogueComplete());
}

// Note: We are not testing the std::cout output or getchar() calls.
// Position management tests are removed as they belong to NPC/specific usage, not Elder logic itself.
// Tests for health, damage, movement, etc. are removed as Elder is an NPC, not a Fighter.