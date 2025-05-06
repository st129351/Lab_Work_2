//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef SLIME_H
#define SLIME_H

#include <iostream>
#include <chrono>
#include "Enemy.h"

class Player;
class GameField; // forward declaration

/**
 * @class Slime
 * @brief Class representing a slime enemy in the game
 * 
 * Slime inherits from the Enemy base class and implements specific slime behavior,
 * including poison attacks and movement patterns.
 */
class Slime : public Enemy
{
private:
    unsigned int poison_damage; ///< Damage dealt by poison effect
    bool is_poisoning;         ///< Flag indicating if poison effect is active
    std::chrono::system_clock::time_point poison_start; ///< Time when poison effect started
    const std::chrono::seconds poison_duration{3}; ///< Duration of poison effect in seconds

public:
    /**
     * @brief Constructor for Slime class
     * 
     * @param name Slime's name
     * @param health Slime's health points
     * @param damage Slime's base damage
     * @param iq Slime's intelligence value
     * @param exp Experience gained for killing the slime
     * @param player Pointer to the player object
     * @param poizon_damage Initial poison damage value
     */
    Slime(std::string name, unsigned int health, unsigned int damage, unsigned int iq, 
          unsigned int exp, Player* player, unsigned int poizon_damage);
    
    /**
     * @brief Default destructor
     */
    ~Slime() = default;
    
    /**
     * @brief Handles slime's death event
     * 
     * Overridden method from the Enemy base class.
     * Gives the player experience and gold for killing the slime.
     */
    void onDeath() override;

    /**
     * @brief Applies poison effect to the player
     * 
     * If poison is not active, starts the poison effect.
     * If poison is active, continues dealing damage until duration expires.
     * 
     * @param player Reference to the player object
     */
    void applyPoison(Player& player);

    /**
     * @brief Gets current poison damage value
     * 
     * @return unsigned int Current poison damage
     */
    unsigned int getPoisonDamage() const;
    
    /**
     * @brief Sets new poison damage value
     * 
     * @param new_poison_damage New poison damage value
     */
    void setPoisonDamage(unsigned int new_poison_damage);

    /**
     * @brief Moves the slime on the game field
     * 
     * The slime moves towards the player if the player is within 6 units distance.
     * Implements basic pathfinding based on relative position to player.
     * 
     * @param player Reference to the player object
     * @param field Reference to the game field
     */
    void move(Player& player, GameField& field) override;
};

#endif