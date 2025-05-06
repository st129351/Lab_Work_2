//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef AHEALTH_H
#define AHEALTH_H

#include "Amulet.h"

class Player;

/**
 * @class AHeal
 * @brief Class representing the Heal Amulet in the game.
 * * The Heal Amulet restores a certain amount of the player's health.
 */
class AHeal : public Amulet
{
private:
    unsigned int heal_value; ///< The amount of health restored by the amulet.
    std::string heal_description; ///< Description of the Heal Amulet's effect.
public:
    /**
     * @brief Constructor for the AHeal class.
     * * Initializes the amulet with a predefined heal value.
     */
    AHeal();

    /**
     * @brief Destructor for the AHeal class.
     * * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    ~AHeal() override;

    /**
     * @brief Applies the Heal Amulet's effect to the player.
     * * Restores the player's health, but does not exceed the maximum health.
     * * @param p Reference to the Player object.
     */
    void use(Player& p) override;

    /**
     * @brief Gets the heal value of the amulet.
     * * @return unsigned int The amount of health restored.
     */
    unsigned int getHealValue() const;

    /**
     * @brief Sets the heal value of the amulet.
     * * @param new_value The new amount of health to restore.
     */
    void setHealValue(unsigned int new_value);
};

#endif