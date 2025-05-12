//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef APERSEVERANCE_H
#define APERSEVERANCE_H

#include "Amulet.h"

class Player;

/**
 * @class APerseverance
 * @brief Class representing the Perseverance Amulet in the game.
 * * APerseverance inherits from the Amulet base class and provides the player with a second chance
 * upon reaching a critical health level.
 */
class APerseverance : public Amulet
{
private:
    unsigned int additional_health; ///< Additional health granted by the amulet.
    bool was_used; ///< Flag indicating if the amulet's effect has been used.
    std::string perseverance_description; ///< Description of the amulet's effect.

public:
    /**
     * @brief Constructor for the APerseverance class.
     * * Initializes the amulet with a predefined additional health value and sets the 'was_used' flag to false.
     */
    APerseverance();

    /**
     * @brief Destructor for the APerseverance class.
     * * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    ~APerseverance() override;

    /**
     * @brief Applies the amulet's effect to the player.
     * * If the player's health is low and the amulet hasn't been used, it restores the player's health
     * and sets the 'was_used' flag to true.
     * * @param p Reference to the Player object.
     */
    void use(Player& p) override;

    /**
     * @brief Gets the additional health provided by the amulet.
     * * @return unsigned int The amount of additional health.
     */
    unsigned int getAdditionalHealth() const;

    /**
     * @brief Sets the additional health provided by the amulet.
     * * @param new_additional_health The new amount of additional health.
     */
    void setAdditionalHealth(unsigned int new_additional_health);

    /**
     * @brief Checks if the amulet's effect has been used.
     * * @return true If the amulet has been used.
     * @return false If the amulet has not been used.
     */
    bool getWasUsed() const;

    /**
     * @brief Sets the 'was_used' flag.
     * * @param new_was_used The new value for the 'was_used' flag.
     */
    void setWasUsed(bool new_was_used);
};

#endif