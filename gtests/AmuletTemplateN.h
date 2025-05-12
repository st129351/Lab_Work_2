//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2
#ifndef AMULETTEMPLATEN_H
#define AMULETTEMPLATEN_H

#include <gtest/gtest.h>
#include "Player.h"
#include <memory>

template <typename T>
class AmuletTest : public ::testing::Test 
{
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<T> amulet;

    void SetUp() override 
    {
        player = std::make_shared<Player>("TestPlayer");
        amulet = std::make_shared<T>();
    }

    void TearDown() override 
    {
    }
};

#endif