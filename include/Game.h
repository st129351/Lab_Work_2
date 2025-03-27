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
    // game process
    // field.slimeSpawn(28, 2); // spawn slime
    // field.banditSpawn(3, 2); // spawn bandit
	// field.yardDragonSpawn(14, 4); // BOSS (yard dragon) spawn
	int input;
    int flag; // = 0

public:
    Game(Player& p);
    ~Game() = default;

    void enableRawMode();
    void disableRawMode();

    void start_game();
};

#endif