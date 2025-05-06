//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef TRADER_H
#define TRADER_H

#include "NPC.h"
#include <sstream>
#include <vector>
#include <memory>

class Amulet;
class Player;
class GameField;
class Enemy;
// forward declaration

/**
 * @class Trader
 * @brief Class representing the trader NPC in the game
 * 
 * Trader inherits from the NPC base class and implements trading functionality,
 * including a store with various amulets that can be purchased by the player.
 */
class Trader : public NPC
{
private:
    std::shared_ptr<Amulet> killer_look; ///< Amulet with killer look effect
    std::shared_ptr<Amulet> fear_death;  ///< Amulet with fear of death effect
    std::shared_ptr<Amulet> madness;     ///< Amulet with madness effect
    std::shared_ptr<Amulet> persev;      ///< Amulet with perseverance effect
    std::shared_ptr<Amulet> best_exp;    ///< Amulet for best experience gain
    std::shared_ptr<Amulet> heal;        ///< Amulet with healing effect
    std::shared_ptr<Amulet> dash;        ///< Amulet with dash ability
    std::vector<std::shared_ptr<Amulet>> amulets; ///< Vector of available amulets
    std::vector<std::shared_ptr<Enemy>> enemies;  ///< Vector of enemies in the game
    Player& player; ///< Reference to the player object
    GameField& field; ///< Reference to the game field
    bool speak_flag; ///< Flag indicating whether trader has spoken

public:
    /**
     * @brief Constructor for Trader class
     * 
     * Initializes the trader with references to player and game field,
     * and creates all available amulets for sale.
     * 
     * @param p Reference to the player object
     * @param f Reference to the game field
     */
    Trader(Player& p, GameField& f);
    
    /**
     * @brief Destructor for Trader class
     */
    ~Trader() override;
    
    /**
     * @brief Initiates dialogue with the trader
     * 
     * Overridden method from the NPC base class.
     * Displays greeting message and shows the store interface.
     */
    void speak() override;
    
    /**
     * @brief Displays the trader's store interface
     * 
     * Generates and returns a formatted string containing information
     * about all available amulets, their costs and slot requirements.
     * 
     * @return std::string Formatted store interface
     */
    std::string showStore();
};

#endif