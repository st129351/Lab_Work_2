//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef AFREAROFDEATH_H
#define AFREAROFDEATH_H

#include "Amulet.h"
#include "Player.h"

/**
 * @class AFearOfDeath
 * @brief Class representing the fear of death amulet in the game.
 * * The fear of death increases the player's damage by a percentage.
 */
class AFearOfDeath : public Amulet
{
private:
    unsigned int additional_damage; ///< The additional damage granted by the amulet.
    std::string fear_of_death_description; ///< Description of the fear of death Amulet's effect.
public:
    /**
     * @brief Constructor for the AFearOfDeath class.
     * * Initializes the amulet, calculating the additional damage based on the player's stats.
     * * @param p Reference to the Player object.
     */
    AFearOfDeath(Player& p);

    /**
     * @brief Destructor for the AFearOfDeath class.
     * * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    ~AFearOfDeath() override;

    /**
     * @brief Applies the Fear of Death Amulet's effect to the player.
     * * Increases the player's damage.
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
};

#endif