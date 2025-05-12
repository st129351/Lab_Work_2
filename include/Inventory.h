//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory> // for smart ptr
#include <string>

// Forward declarations
class Player;
class Amulet;

/**
 * @class Inventory
 * @brief Represents the player's inventory in the game.
 *
 * The inventory manages a collection of items, specifically Amulets in this case.
 * It has a limited number of slots and provides functionality to add, show,
 * and manage items.
 */
class Inventory
{
private:
    const unsigned int max_slots = 25;  ///< Maximum number of slots in the inventory.
    unsigned int size; ///< Current number of occupied slots.
    Player& player; ///< Reference to the player who owns the inventory.
    std::vector<std::shared_ptr<Amulet>> amulets; ///< Vector of smart pointers to Amulet items.
    // Using shared_ptr for automatic memory management.

public:
    /**
     * @brief Constructor for the Inventory class.
     *
     * Initializes an empty inventory for the given player.
     *
     * @param p Reference to the Player object.
     */
    Inventory(Player& p);

    /**
     * @brief Shows the contents of the inventory.
     *
     * Generates a string representation of the inventory,
     * including the size and list of items.
     *
     * @return std::string String representation of the inventory.
     */
    std::string show();

    /**
     * @brief Adds an item to the inventory.
     *
     * Adds the given Amulet to the inventory if there are enough free slots.
     *
     * @param item Shared pointer to the Amulet to be added.
     */
    void add(std::shared_ptr<Amulet> item);

    /**
     * @brief Gets the number of available slots in the inventory.
     *
     * @return unsigned int Number of available slots.
     */
    unsigned int getAvailableSlots() const;
};

#endif