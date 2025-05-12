//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Inventory.h"
#include "Fighter.h"

class NPC;
class Enemy;
class AFearOfDeath;
class YardDragon;
class Slime;
class Bandit;
class GameField;
class AKillerLook;
class AMadness;
class APerseverance;
class BestExp;
class AHeal;
class ADash;
// forward declaration

/**
 * @class Player
 * @brief Class representing the player character in the game
 * 
 * Player inherits from the Fighter base class and implements all player-specific functionality,
 * including movement, combat, inventory management, and interaction with NPCs and items.
 */
class Player : public Fighter
{
private:
    std::string name; ///< Player's name
    unsigned int level; ///< Current player level
    const unsigned int max_level; ///< Maximum possible player level
    unsigned int exp; ///< Current experience points
    unsigned int gold; ///< Current amount of gold
    int x_pos; ///< X-coordinate position on the game field
    int y_pos; ///< Y-coordinate position on the game field
    bool persev_flag; ///< Flag indicating if Perseverance amulet is active
    bool best_exp_flag; ///< Flag indicating if BestExp amulet is active
    bool heal_flag; ///< Flag indicating if Heal amulet is active
    bool dash_flag; ///< Flag indicating if Dash amulet is active
    Inventory inventory; ///< Player's inventory system
    std::vector<std::shared_ptr<Enemy>> enemies; ///< List of enemies in the game

    // Amulet pointers
    std::shared_ptr<AFearOfDeath> fear_death; ///< Fear of Death amulet
    std::shared_ptr<AKillerLook> killer_look; ///< Killer Look amulet
    std::shared_ptr<AMadness> madness; ///< Madness amulet
    std::shared_ptr<APerseverance> persev; ///< Perseverance amulet
    std::shared_ptr<BestExp> best_exp; ///< Best Experience amulet
    std::shared_ptr<AHeal> heal; ///< Healing amulet
    std::shared_ptr<ADash> dash; ///< Dash ability amulet
    
    /**
     * @struct AttackVisual
     * @brief Structure for storing coordinates of attack visual effects
     */
    struct AttackVisual
    {
        int x, y; ///< Coordinates of attack effect on the game field
    };
    std::vector<AttackVisual> attack_visuals; ///< Vector of attack visual effects

public:
    /**
     * @brief Constructor for Player class
     * 
     * @param name Player's name
     */
    Player(std::string name);
    
    /**
     * @brief Handles player's death event
     * 
     * Overridden method from the Fighter base class.
     * Sets health to 0 and displays game over message.
     */
    void onDeath() override;
    
    /**
     * @brief Increases player's level if possible
     * 
     * Increases level, resets experience, and boosts stats if not at max level.
     */
    void levelUp();

    /**
     * @brief Displays player's inventory contents
     * 
     * @return std::string Formatted inventory information
     */
    std::string showInventory();

    /**
     * @brief Purchases an item from an NPC
     * 
     * @param npc_characters List of NPCs in the game
     * @param symb Character representing the item to buy
     * @param field Reference to the game field
     */
    void Buy(std::vector<std::shared_ptr<NPC>> npc_characters, char symb, GameField& field);
    
    /**
     * @brief Initiates dialogue with nearby NPCs
     * 
     * @param npc_characters List of NPCs in the game
     */
    void NPCSpeak(std::vector<std::shared_ptr<NPC>> npc_characters);
    
    /**
     * @brief Performs area attack around the player
     * 
     * @param field Reference to the game field
     * @param enemies List of enemies in the game
     */
    void attackArea(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies);
    
    /**
     * @brief Updates attack visual effects on the game field
     * 
     * @param field Reference to the game field
     * @param enemies List of enemies in the game
     */
    void UpdateAttackVisual(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies);

    // Getters section
    
    /**
     * @brief Gets current experience points
     * 
     * @return unsigned int Current experience
     */
    unsigned int getExp() const;
    
    /**
     * @brief Gets current gold amount
     * 
     * @return unsigned int Current gold
     */
    unsigned int getGold() const;
    
    /**
     * @brief Gets current player level
     * 
     * @return unsigned int Current level
     */
    unsigned int getLevel() const;
    
    /**
     * @brief Gets maximum player level
     * 
     * @return unsigned int Maximum level
     */
    unsigned int getMaxLevel() const;
    
    /**
     * @brief Gets player's name
     * 
     * @return std::string Player's name
     */
    std::string getName() const;
    
    /**
     * @brief Gets X-coordinate position
     * 
     * @return int X position
     */
    int getX_pos() const;
    
    /**
     * @brief Gets Y-coordinate position
     * 
     * @return int Y position
     */
    int getY_pos() const;
    
    /**
     * @brief Checks if Perseverance amulet is active
     * 
     * @return bool True if active, false otherwise
     */
    bool getPersevFlag() const;
    
    /**
     * @brief Checks if BestExp amulet is active
     * 
     * @return bool True if active, false otherwise
     */
    bool getBestExpFlag() const;
    
    /**
     * @brief Checks if Heal amulet is active
     * 
     * @return bool True if active, false otherwise
     */
    bool getHealFlag() const;
    
    /**
     * @brief Checks if Dash amulet is active
     * 
     * @return bool True if active, false otherwise
     */
    bool getDashFlag() const;
    
    /**
     * @brief Gets Perseverance amulet
     * 
     * @return std::shared_ptr<APerseverance> Pointer to amulet
     */
    std::shared_ptr<APerseverance> getPersev();
    
    /**
     * @brief Gets BestExp amulet
     * 
     * @return std::shared_ptr<BestExp> Pointer to amulet
     */
    std::shared_ptr<BestExp> getBestExp();
    
    /**
     * @brief Gets Heal amulet
     * 
     * @return std::shared_ptr<AHeal> Pointer to amulet
     */
    std::shared_ptr<AHeal> getHeal();
    
    /**
     * @brief Gets Dash amulet
     * 
     * @return std::shared_ptr<ADash> Pointer to amulet
     */
    std::shared_ptr<ADash> getDash();
    
    /**
     * @brief Gets Madness amulet
     * 
     * @return std::shared_ptr<AMadness> Pointer to amulet
     */
    std::shared_ptr<AMadness> getMadness();
    
    /**
     * @brief Gets KillerLook amulet
     * 
     * @return std::shared_ptr<AKillerLook> Pointer to amulet
     */
    std::shared_ptr<AKillerLook> getKillerLook();
    
    /**
     * @brief Gets FearOfDeath amulet
     * 
     * @return std::shared_ptr<AFearOfDeath> Pointer to amulet
     */
    std::shared_ptr<AFearOfDeath> getFearOfDeath();

    // Setters section
    
    /**
     * @brief Sets new experience value
     * 
     * @param new_exp New experience value
     */
    void setExp(unsigned int new_exp);
    
    /**
     * @brief Sets new gold amount
     * 
     * @param new_gold New gold value
     */
    void setGold(unsigned int new_gold);
    
    /**
     * @brief Sets new player level
     * 
     * @param new_level New level value
     */
    void setLevel(unsigned int new_level);
    
    /**
     * @brief Sets new player name
     * 
     * @param new_name New name
     */
    void setName(const std::string& new_name);
    
    /**
     * @brief Sets new X-coordinate position
     * 
     * @param new_x_pos New X position
     */
    void setX_pos(unsigned int new_x_pos);
    
    /**
     * @brief Sets new Y-coordinate position
     * 
     * @param new_y_pos New Y position
     */
    void setY_pos(unsigned int new_y_pos);
};

#endif