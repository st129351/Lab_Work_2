//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef AMADNESS_H
#define AMADNESS_H

#include "Amulet.h"

class Player;

/**
 * @class AMadness
 * @brief Class representing the Madness Amulet in the game.
 * * The Madness Amulet increases the player's damage but has a side effect of reducing their health.
 */
class AMadness : public Amulet
{
private:
    unsigned int additional_damage; ///< The additional damage granted by the amulet.
    unsigned int side_effect; ///< The health reduction side effect of using the amulet.
    std::string madness_description; ///< Description of the Madness Amulet's effect.

public:
    /**
     * @brief Constructor for the AMadness class.
     * * @param p Reference to the Player object.
     * * Initializes the amulet, calculating the additional damage and side effect based on the player's stats.
     */
    AMadness(Player& p);

    /**
     * @brief Destructor for the AMadness class.
     * * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    ~AMadness() override;

    /**
     * @brief Applies the Madness Amulet's effect to the player.
     * * Increases the player's damage and reduces their health.
     * * @param p Reference to the Player object.
     */
    void use(Player& p) override;

    /**
     * @brief Gets the additional damage provided by the amulet.
     * * @return unsigned int The amount of additional damage.
     */
    unsigned int getAdditionalDamage() const;

    /**
     * @brief Sets the additional damage provided by the amulet.
     * * @param new_additional_damage The new amount of additional damage.
     */
    void setAdditionalDamage(unsigned int new_additional_damage);

    /**
     * @brief Gets the health reduction side effect of the amulet.
     * * @return unsigned int The amount of health reduction.
     */
    unsigned int getSideEffect() const;

    /**
     * @brief Sets the health reduction side effect of the amulet.
     * * @param new_side_effect The new amount of health reduction.
     */
    void setSideEffect(unsigned int new_side_effect);
};

#endif