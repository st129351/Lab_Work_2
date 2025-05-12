//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2

#include <gtest/gtest.h>
#include "AKillerLook.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
#include <cmath> // For std::floor

// Mock Enemy class for controlled testing
class MockEnemy : public Enemy {
public:
    // Corrected constructor call for Enemy base class
    MockEnemy(const std::string& name, int health, int damage, int iq, unsigned int exp, Player* player)
        : Enemy(name, health, damage, iq, exp, player) {}

    // Implement pure virtual functions from base classes
    void move(Player& player, GameField& field) override {
        // Mock implementation - behavior not relevant for AKillerLook test
    }

    void onDeath() override {
        // Mock implementation - behavior not relevant for AKillerLook test
    }

    // Removed non-virtual methods mistakenly marked override:
    // void specialAttack(Player& player) { /* Mock */ };
    // std::string getDescription() const { return "Mock Enemy"; };

    // Use public setters from base classes
    void test_setDamage(unsigned int new_damage) {
        // Need to pass by reference to setDamage
        unsigned int damage_val = new_damage;
        setDamage(damage_val);
    }
    void test_setIQ(unsigned int new_iq) {
        setIQ(new_iq);
    }
};

class AKillerLookTest : public ::testing::Test {
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<AKillerLook> amulet;
    std::vector<std::shared_ptr<Enemy>> test_enemies;

    void SetUp() override {
        player = std::make_shared<Player>("TestPlayer");
        player->setLevel(2); // Set player level > 1 for noticeable effect

        // Create mock enemies using the corrected constructor
        // Adding exp and player arguments
        auto enemy1 = std::make_shared<MockEnemy>("Mock1", 100, 50, 20, 10, player.get());
        auto enemy2 = std::make_shared<MockEnemy>("Mock2", 100, 10, 5, 5, player.get());
        auto enemy3 = std::make_shared<MockEnemy>("Mock3", 100, 5, 1, 2, player.get());

        test_enemies.push_back(enemy1);
        test_enemies.push_back(enemy2);
        test_enemies.push_back(enemy3);

        amulet = std::make_shared<AKillerLook>(test_enemies);
    }

    void TearDown() override {
        // Smart pointers handle cleanup
    }
};

TEST_F(AKillerLookTest, Init) {
    EXPECT_EQ(amulet->getCost(), 105);
    EXPECT_EQ(amulet->getName(), "killer look");
    // Note: Original description has a typo "tremblue". Test against the actual implemented string.
    EXPECT_EQ(amulet->getKillerLookDescription(), "Your enemies will tremblue at the knees \njust looking at you");
    EXPECT_EQ(amulet->getDescription(), "Your enemies will tremble at the knees \njust looking at you"); // Base class description
    EXPECT_EQ(amulet->getSlots(), 5);
    EXPECT_EQ(amulet->getUsage(), false);
    EXPECT_EQ(amulet->getFearPercentage(), 15);
}

TEST_F(AKillerLookTest, UseEffect) {
    // Initial state checks (based on SetUp)
    unsigned int initial_damage1 = test_enemies[0]->getDamage(); // 50
    unsigned int initial_iq1 = test_enemies[0]->getIQ();       // 20
    unsigned int initial_damage2 = test_enemies[1]->getDamage(); // 10
    unsigned int initial_iq2 = test_enemies[1]->getIQ();       // 5
    unsigned int initial_damage3 = test_enemies[2]->getDamage(); // 5
    unsigned int initial_iq3 = test_enemies[2]->getIQ();       // 1

    unsigned int player_level = player->getLevel(); // 2
    unsigned int fear_percent = amulet->getFearPercentage(); // 15

    // Use the amulet
    amulet->use(*player);

    // Calculate expected damage reduction
    // Enemy 1: reduce = floor(20 * (15 * 2) / 100) = floor(20 * 30 / 100) = floor(6) = 6. New damage = 50 - 6 = 44
    unsigned int expected_reduce1 = std::floor(initial_iq1 * (fear_percent * player_level) / 100.0);
    unsigned int expected_damage1 = initial_damage1 - expected_reduce1;
    EXPECT_EQ(test_enemies[0]->getDamage(), expected_damage1);

    // Enemy 2: reduce = floor(5 * (15 * 2) / 100) = floor(5 * 30 / 100) = floor(1.5) = 1. New damage = 10 - 1 = 9
    unsigned int expected_reduce2 = std::floor(initial_iq2 * (fear_percent * player_level) / 100.0);
    unsigned int expected_damage2 = initial_damage2 - expected_reduce2;
    EXPECT_EQ(test_enemies[1]->getDamage(), expected_damage2);

    // Enemy 3: reduce = floor(1 * (15 * 2) / 100) = floor(1 * 30 / 100) = floor(0.3) = 0.
    // Reduction (0) is not > initial damage (5). New damage = 5 - 0 = 5.
    // Wait, the code checks `if (reduce > enemy->getDamage())`. Let's re-read the code.
    // Ah, `if (reduce > enemy->getDamage()) { enemy->setDamage(1); } else { enemy->setDamage(enemy->getDamage() - reduce); }`
    // For Enemy 3: reduce is 0. Is 0 > 5? No. So damage becomes 5 - 0 = 5.
    unsigned int expected_reduce3 = std::floor(initial_iq3 * (fear_percent * player_level) / 100.0);
    unsigned int expected_damage3;
    if (expected_reduce3 > initial_damage3) {
        expected_damage3 = 1;
    } else {
        expected_damage3 = initial_damage3 - expected_reduce3;
    }
    EXPECT_EQ(test_enemies[2]->getDamage(), expected_damage3); // Should be 5

    // Test edge case where reduction > initial damage
    auto enemy4 = std::make_shared<MockEnemy>("Mock4", 100, 5, 50, 15, player.get()); // High IQ, low damage
    test_enemies.push_back(enemy4);
    // Re-create amulet with the new enemy list (or modify the existing one if possible, but cleaner to re-create for test isolation)
    amulet = std::make_shared<AKillerLook>(test_enemies);

    unsigned int initial_damage4 = enemy4->getDamage(); // 5
    unsigned int initial_iq4 = enemy4->getIQ();       // 50

    amulet->use(*player);

    // Enemy 4: reduce = floor(50 * (15 * 2) / 100) = floor(50 * 30 / 100) = floor(15) = 15.
    // Is 15 > 5? Yes. New damage should be 1.
    unsigned int expected_reduce4 = std::floor(initial_iq4 * (fear_percent * player_level) / 100.0);
    unsigned int expected_damage4;
     if (expected_reduce4 > initial_damage4) {
        expected_damage4 = 1;
    } else {
        expected_damage4 = initial_damage4 - expected_reduce4;
    }
    EXPECT_EQ(enemy4->getDamage(), expected_damage4); // Should be 1

}