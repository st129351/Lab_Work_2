//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef AMULET_H
#define AMULET_H

#include <iostream>
#include <string>
#include "Enemy.h"

class Player;

/**
 * @class Amulet
 * @brief Base class representing an amulet in the game.
 * * Amulets are items that provide special abilities or bonuses to the player.
 */
class Amulet
{
private:
    unsigned int cost; ///< Cost of the amulet.
    bool usage; ///< Indicates if the amulet can be used.
    std::string name; ///< Name of the amulet.
    std::string description; ///< Description of the amulet's effect.
    unsigned int slots; ///< Number of inventory slots the amulet occupies.

public:
    /**
     * @brief Constructor for the Amulet class.
     * * @param cost The cost of the amulet.
     * @param usage Indicates if the amulet can be used.
     * @param name The name of the amulet.
     * @param description The description of the amulet's effect.
     * @param slots The number of inventory slots the amulet occupies.
     */
    Amulet(unsigned int cost, bool usage, std::string name, std::string description, unsigned int slots);

    /**
     * @brief Virtual destructor for the Amulet class.
     * * Ensures proper cleanup of derived class objects.
     */
    virtual ~Amulet() = default;

    /**
     * @brief Pure virtual function to use the amulet's effect.
     * * Must be implemented by derived classes.
     * * @param player Reference to the Player object.
     */
    virtual void use(Player& player) = 0;
    // redefinition in different amulets
    // = 0 - pure virtual func (not realise in base class)

    /**
     * @brief Gets the cost of the amulet.
     * * @return unsigned int The cost of the amulet.
     */
    unsigned int getCost() const;

    /**
     * @brief Checks if the amulet can be used.
     * * @return bool True if the amulet can be used, false otherwise.
     */
    bool getUsage() const;

    /**
     * @brief Gets the name of the amulet.
     * * @return std::string The name of the amulet.
     */
    std::string getName() const;

    /**
     * @brief Gets the description of the amulet's effect.
     * * @return std::string The description of the amulet.
     */
    std::string getDescription() const;

    /**
     * @brief Gets the number of inventory slots the amulet occupies.
     * * @return unsigned int The number of slots.
     */
    unsigned int getSlots() const;

    /**
     * @brief Sets the number of inventory slots the amulet occupies.
     * * @param new_slots The new number of slots.
     */
    void setSlots(unsigned int new_slots);

    /**
     * @brief Sets the cost of the amulet.
     * * @param new_cost The new cost of the amulet.
     */
    void setCost(unsigned int new_cost);

    /**
     * @brief Sets the usage status of the amulet.
     * * @param new_usage The new usage status (true if usable, false otherwise).
     */
    void setUsage(bool new_usage);

    /**
     * @brief Sets the name of the amulet.
     * * @param new_name The new name of the amulet.
     */
    void setName(std::string new_name);

    /**
     * @brief Sets the description of the amulet's effect.
     * * @param new_description The new description of the amulet.
     */
    void setDescription(std::string new_description);
};

#endif