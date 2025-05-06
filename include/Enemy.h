//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef ENEMY_H
#define ENEMY_H

#include "Fighter.h"

class GameField;
class Player; // forward declarations

/**
 * @class Enemy
 * @brief Base class for all enemies in the game.
 *
 * The Enemy class inherits from Fighter and adds properties and functions
 * specific to enemies, such as enemy description, IQ, position, and experience points.
 */
class Enemy : public Fighter
{
private:
    std::string enemy_description; ///< Description of the enemy.
    unsigned int iq; ///< Intelligence quotient of the enemy.
    int x_pos; ///< X-coordinate of the enemy's position.
    int y_pos; ///< Y-coordinate of the enemy's position.
    unsigned int exp;///< Experience points awarded for defeating the enemy.
    Player* player; ///< Pointer to the Player object.

public:
    /**
     * @brief Constructor for the Enemy class.
     *
     * @param name   Name of the enemy.
     * @param health Initial health of the enemy.
     * @param damage Attack damage of the enemy.
     * @param iq     Intelligence quotient of the enemy.
     * @param exp    Experience points awarded for defeating the enemy.
     * @param player Pointer to the Player object.
     */
    Enemy(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player);

    /**
     * @brief Virtual destructor for the Enemy class.
     *
     * Ensures proper cleanup of derived class objects.
     */
    virtual ~Enemy() = default;

    /**
     * @brief Gets the description of the enemy.
     *
     * @return The description of the enemy.
     */
    std::string getEnemyDescription() const;

    /**
     * @brief Sets a new description for the enemy.
     *
     * @param new_enemy_description The new description.
     */
    void setEnemyDescription(const std::string& new_enemy_description);

    /**
     * @brief Gets the intelligence quotient of the enemy.
     *
     * @return The IQ of the enemy.
     */
    unsigned int getIQ() const;

    /**
     * @brief Sets a new intelligence quotient for the enemy.
     *
     * @param new_iq The new IQ.
     */
    void setIQ(unsigned int new_iq);

    /**
     * @brief Gets the experience points awarded for defeating the enemy.
     *
     * @return The experience points.
     */
    unsigned int getExp() const;

    /**
     * @brief Sets the experience points awarded for defeating the enemy.
     *
     * @param new_exp The new experience points.
     */
    void setExp(unsigned int new_exp);

    /**
     * @brief Gets a reference to the Player object.
     *
     * @return A reference to the Player object.
     */
    Player& getPlayer();

    /**
     * @brief Sets a new Player object for the enemy.
     *
     * @param new_player The new Player object.
     */
    void setPlayer(Player* new_player);

    /**
     * @brief Pure virtual function for enemy movement.
     *
     * Must be implemented in derived classes to define specific movement behavior.
     *
     * @param player Reference to the Player object.
     * @param field  Reference to the GameField object.
     */
    virtual void move(Player& player, GameField& field) = 0;

    /**
     * @brief Gets the X-coordinate of the enemy's position.
     *
     * @return The X-coordinate.
     */
    virtual int getX_pos() const;

    /**
     * @brief Gets the Y-coordinate of the enemy's position.
     *
     * @return The Y-coordinate.
     */
    virtual int getY_pos() const;

    /**
     * @brief Sets the X-coordinate of the enemy's position.
     *
     * @param new_x_pos The new X-coordinate.
     */
    virtual void setX_pos(unsigned int new_x_pos);

    /**
     * @brief Sets the Y-coordinate of the enemy's position.
     *
     * @param new_y_pos The new Y-coordinate.
     */
    virtual void setY_pos(unsigned int new_y_pos);
};

#endif