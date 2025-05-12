//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
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

/**
 * @class Game
 * @brief Manages the overall game flow and logic.
 *
 * The Game class handles the initialization, running, and termination of the game.
 * It manages the player, game field, and game levels.
 */
class Game
{
private:
    Player player; ///< The player in the game.
    std::shared_ptr<YardDragon> dragon; ///< Shared pointer to the YardDragon.
    GameField field; ///< The game field.
    int input; ///< User input.
    int flag; ///< Game state flag.
    bool completeLevel; ///< Flag indicating if the level is complete.
    bool endGame; ///< Flag indicating if the game has ended.

public:
    /**
     * @brief Constructor for the Game class.
     *
     * Initializes the game with the player and game field.
     *
     * @param p Reference to the Player object.
     */
    Game(Player& p);

    /**
     * @brief Default destructor for the Game class.
     */
    ~Game() = default;

    /**
     * @brief Enables raw mode for terminal input.
     *
     * Raw mode allows reading input without waiting for the Enter key.
     */
    void enableRawMode();

    /**
     * @brief Disables raw mode for terminal input.
     *
     * Returns the terminal to its original settings.
     */
    void disableRawMode();

    /**
     * @brief Starts the main game loop.
     *
     * Handles game logic, input, and rendering.
     */
    void start_game();

    /**
     * @brief Starts the village level.
     *
     * Initializes and runs the village level.
     */
    void startVillage();

    /**
     * @brief Runs Level 1 of the game.
     *
     * Initializes and manages the gameplay for Level 1.
     */
    void Level_1();

    /**
     * @brief Runs Level 2 of the game.
     *
     * Initializes and manages the gameplay for Level 2.
     */
    void Level_2();

    /**
     * @brief Runs Level 3 of the game.
     *
     * Initializes and manages the gameplay for Level 3.
     */
    void Level_3();
};

#endif