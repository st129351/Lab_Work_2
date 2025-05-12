//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "Fighter.h"
#include <memory>
#include <string>

// Minimal concrete derived class for testing Fighter
class TestFighter : public Fighter {
public:
    bool onDeathCalled = false; // Flag to check if onDeath was called

    // Use the base class constructor
    TestFighter(const std::string& name, unsigned int health, unsigned int damage)
        : Fighter(name, health, damage) {}

    // Provide implementation for the pure virtual function
    void onDeath() override {
        onDeathCalled = true;
        // Dummy implementation
    }
};

class FighterBaseTest : public ::testing::Test {
protected:
    std::shared_ptr<TestFighter> fighter1;
    std::shared_ptr<TestFighter> fighter2;

    // Initial values
    const std::string initial_name1 = "Fighter1";
    const unsigned int initial_health1 = 100;
    const unsigned int initial_damage1 = 10;

    const std::string initial_name2 = "Fighter2";
    const unsigned int initial_health2 = 80;
    const unsigned int initial_damage2 = 5;

    void SetUp() override {
        fighter1 = std::make_shared<TestFighter>(initial_name1, initial_health1, initial_damage1);
        fighter2 = std::make_shared<TestFighter>(initial_name2, initial_health2, initial_damage2);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(FighterBaseTest, Init) {
    EXPECT_EQ(fighter1->getName(), initial_name1);
    EXPECT_EQ(fighter1->getHealth(), initial_health1);
    EXPECT_EQ(fighter1->getDamage(), initial_damage1);
    EXPECT_FALSE(fighter1->onDeathCalled);

    EXPECT_EQ(fighter2->getName(), initial_name2);
    EXPECT_EQ(fighter2->getHealth(), initial_health2);
    EXPECT_EQ(fighter2->getDamage(), initial_damage2);
    EXPECT_FALSE(fighter2->onDeathCalled);
}

TEST_F(FighterBaseTest, GettersAndSetters) {
    unsigned int new_health = 90;
    unsigned int new_damage = 15;
    std::string new_name = "NewName";

    fighter1->setHealth(new_health);
    fighter1->setDamage(new_damage);
    fighter1->setName(new_name);

    EXPECT_EQ(fighter1->getHealth(), new_health);
    EXPECT_EQ(fighter1->getDamage(), new_damage);
    EXPECT_EQ(fighter1->getName(), new_name);
}

TEST_F(FighterBaseTest, TakeDamageAndIsAlive) {
    EXPECT_TRUE(fighter1->isAlive());
    EXPECT_EQ(fighter1->getHealth(), initial_health1);
    EXPECT_FALSE(fighter1->onDeathCalled);

    unsigned int damage1 = 30;
    fighter1->takeDamage(damage1); // Non-fatal
    EXPECT_TRUE(fighter1->isAlive());
    EXPECT_EQ(fighter1->getHealth(), initial_health1 - damage1);
    EXPECT_FALSE(fighter1->onDeathCalled); // onDeath should not be called

    // Take fatal damage
    fighter1->takeDamage(initial_health1); // Damage >= remaining health
    EXPECT_FALSE(fighter1->isAlive());
    EXPECT_EQ(fighter1->getHealth(), 0);
    EXPECT_TRUE(fighter1->onDeathCalled); // onDeath SHOULD be called by takeDamage

    // Reset flag and test taking damage when already dead
    fighter1->onDeathCalled = false;
    fighter1->takeDamage(10);
    EXPECT_FALSE(fighter1->isAlive());
    EXPECT_EQ(fighter1->getHealth(), 0);
    EXPECT_FALSE(fighter1->onDeathCalled); // onDeath shouldn't be called again
}

TEST_F(FighterBaseTest, Attack) {
    unsigned int f2_health_before = fighter2->getHealth();
    unsigned int f1_damage = fighter1->getDamage();

    fighter1->attack(*fighter2); // fighter1 attacks fighter2

    EXPECT_EQ(fighter2->getHealth(), f2_health_before - f1_damage);
    EXPECT_FALSE(fighter2->onDeathCalled); // Damage was not fatal

    // Make fighter1 strong enough to kill fighter2
    unsigned int hp = initial_health2 + 10;
    fighter1->setDamage(hp);
    f2_health_before = fighter2->getHealth(); // Health is already reduced

    fighter1->attack(*fighter2); // Fatal attack

    EXPECT_FALSE(fighter2->isAlive());
    EXPECT_EQ(fighter2->getHealth(), 0);
    EXPECT_TRUE(fighter2->onDeathCalled); // onDeath should be called via takeDamage
}

// Removed incorrect tests 