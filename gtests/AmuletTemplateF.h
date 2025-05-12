//Lichkovaha Daniil
//st129351@student.spbu.ru
//Lab_Work_2
#ifndef AMULETTEMPLATEF_H
#define AMULETTEMPLATEF_H

#include <gtest/gtest.h>
#include "YardDragon.h"
#include "GameField.h"
#include "Player.h"
#include <memory>

template <typename T>
class AmuletTest : public ::testing::Test 
{
protected:
    std::shared_ptr<Player> player;
    std::shared_ptr<YardDragon> dragon;
    std::shared_ptr<GameField> field;
    std::shared_ptr<T> amulet;

    void SetUp() override 
    {
        player = std::make_shared<Player>("drawi");
        dragon = std::make_shared<YardDragon>("Yard Dragon", 200, 30, 45, 100, player.get(), 5);
        field = std::make_shared<GameField>(*player, dragon);
        amulet = std::make_shared<T>(*field);
    }

    void TearDown() override 
    {
    }
};

#endif