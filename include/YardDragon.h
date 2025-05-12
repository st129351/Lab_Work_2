//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef YARDDRAGON_H
#define YARDDRAGON_H

#include "Enemy.h"
#include <iostream>
#include <string>
#include <vector>

class Player;
class GameField;
// not suitable, when using the object of class (now ptr in constructor)

/**
 * @class YardDragon
 * @brief Class representing the yard dragon in the game
 * 
 * YardDragon inherits from the Enemy base class and implements specific dragon behavior,
 * including fire attacks and corresponding visual effects.
 */
class YardDragon : public Enemy
{
private:
    int attack_range; ///< Dragon's attack range
    bool can_move; ///< Flag indicating whether the dragon can move
    int fire_count; ///< Fire counter (updated in the main game loop)
    
    /**
     * @struct FireVisual
     * @brief Structure for storing coordinates of fire visual effects
     */
    struct FireVisual
    {
        int x, y; ///< Coordinates of fire effect on the game field
    };
    std::vector<FireVisual> fire_visuals; ///< Vector of fire visual effects

public:
    /**
     * @brief Constructor for YardDragon class
     * 
     * @param name Dragon's name
     * @param health Dragon's health
     * @param damage Dragon's damage
     * @param iq Dragon's intelligence
     * @param exp Experience gained for killing the dragon
     * @param player Pointer to the player object
     * @param attack_range Dragon's attack range
     */
    YardDragon(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player, int attack_range);
    
    /**
     * @brief Default destructor
     */
    ~YardDragon() = default;
    
    /**
     * @brief Handles dragon's death event
     * 
     * Overridden method from the Enemy base class.
     * Gives the player experience and gold for killing the dragon.
     */
    void onDeath() override;

    /**
     * @brief Performs dragon's fire attack
     * 
     * Creates fire visual effects on the game field and damages the player
     * if they are in the area of effect.
     * 
     * @param field Reference to the game field
     * @param player Reference to the player
     */
    void FireAttack(GameField& field, Player& player);
    
    /**
     * @brief Updates fire visual effects on the game field
     * 
     * @param field Reference to the game field
     * @param player Reference to the player
     */
    void UpdateFireVisual(GameField& field, Player& player);

    /**
     * @brief Gets the dragon's attack range
     * 
     * @return unsigned int Current attack range
     */
    unsigned int getAttackRange() const;
    
    /**
     * @brief Sets a new attack range for the dragon
     * 
     * @param new_range New attack range
     */
    void setAttackRange(int new_range);
    
    /**
     * @brief Gets the current value of the fire counter
     * 
     * @return int Current value of the fire counter
     */
    int getFireCount() const;
    
    /**
     * @brief Sets a new value for the fire counter
     * 
     * @param new_value New value for the fire counter
     */
    void setFireCount(int new_value);
    
    /**
     * @brief Checks if the dragon can move
     * 
     * @return true If the dragon can move
     * @return false If the dragon cannot move
     */
    bool getCanMove() const;
    
    /**
     * @brief Sets the dragon's ability to move
     * 
     * @param new_value New value for the movement flag
     */
    void setCanMove(bool new_value);

    /**
     * @brief Moves the dragon on the game field
     * 
     * The dragon moves towards the player if the player is within the dragon's field of vision.
     * If the dragon cannot move (can_move flag is false), the function does nothing.
     * 
     * @param player Reference to the player
     * @param field Reference to the game field
     */
    void move(Player& player, GameField& field) override;
};

#endif