//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2
#ifndef AMULETTEMPLATEP_H
#define AMULETTEMPLATEP_H

#include <gtest/gtest.h>
// Removed unused headers: YardDragon.h, GameField.h
#include "Player.h"
#include <memory> // Keep for shared_ptr

// Forward declare the amulet type being tested
// This avoids needing to include specific amulet headers here
// template <typename T>
// class T; // This doesn't work directly, the specific amulet header is needed where this template is used.


template <typename T> // T should be a class derived from Amulet
class AmuletTest : public ::testing::Test
{
protected:
    // Removed unused members: dragon, field
    std::shared_ptr<Player> player; // Use smart pointer
    std::shared_ptr<T> amulet;      // Use smart pointer

    void SetUp() override
    {
        player = std::make_shared<Player>("TestPlayer"); // Create player first
        // Assuming Amulet constructor takes Player&
        amulet = std::make_shared<T>(*player); // Create amulet with player reference
    }

    void TearDown() override
    {
        // No manual deletion needed with smart pointers
    }
};

#endif