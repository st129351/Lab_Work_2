//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef BANDIT_H
#define BANDIT_H

#include "Enemy.h"

class Player;
class GameField;
// forwad declaration

/**
 * @class Bandit
 * @brief Represents a Bandit enemy in the game.
 *
 * The Bandit class inherits from Enemy and implements specific behavior
 * for bandit enemies, including actions upon death and movement patterns.
 */
class Bandit : public Enemy
{
public:
    /**
     * @brief Constructor for the Bandit class.
     *
     * @param name   Name of the bandit.
     * @param health Initial health of the bandit.
     * @param damage Attack damage of the bandit.
     * @param iq     Intelligence quotient of the bandit.
     * @param exp    Experience points awarded for defeating the bandit.
     * @param player Pointer to the Player object.
     */
    Bandit(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player);

    /**
     * @brief Default destructor for the Bandit class.
     */
    ~Bandit() = default;

    /**
     * @brief Handles the bandit's actions upon death.
     *
     * Overrides the onDeath() method from the Enemy class to define specific
     * behavior when the bandit is defeated, such as awarding experience and gold to the player.
     */
    void onDeath() override;

    /**
     * @brief Defines the movement pattern of the bandit.
     *
     * Overrides the move() method from the Enemy class to implement specific
     * movement logic for bandits, such as chasing the player within a certain range.
     *
     * @param player Reference to the Player object.
     * @param field  Reference to the GameField object.
     */
    void move(Player& player, GameField& field) override;
};

#endif