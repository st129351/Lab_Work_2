#ifndef GAME_H
#define GAME_H

#include <gtest/gtest.h>
#include <cstdio>
#include <iostream>
#include <termios.h>
#include <unistd.h>


#include "Player.h"
#include "GameField.h"

class YardDragon;

class Game
{
private:
    Player player;
    std::shared_ptr<YardDragon> dragon; // = std::make_shared<YardDragon>("Yard Dragon", 200, 30, 45, 100, &player, 4)
    GameField field; // (player, dragon)
	int input;
    int flag;
    bool completeLevel;
    bool endGame;
public:
    Game(Player& p);
    ~Game() = default;

    void enableRawMode();
    void disableRawMode();
    void start_game();
    void startVillage();
    void Level_1();
    void Level_2();
    void Level_3();
};

#endif