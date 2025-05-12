//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef AKILLERLOOK_H
#define AKILLERLOOK_H

#include "Amulet.h"
#include <memory>

class Player;
class Enemy;
class GameField;

/**
 * @class AKillerLook
 * @brief Class representing the Killer Look Amulet in the game.
 * * The Killer Look Amulet reduces the damage of enemies based on the player's level and the enemy's intelligence.
 */
class AKillerLook : public Amulet
{
private:
    const unsigned int fear_percentage; ///< The percentage by which to reduce enemy damage.
    std::string killer_look_description; ///< Description of the Killer Look Amulet's effect.
    std::vector<std::shared_ptr<Enemy>> enemies; ///< Vector of enemies affected by the amulet.

public:
    /**
     * @brief Constructor for the AKillerLook class.
     * * @param e Vector of shared pointers to Enemy objects that will be affected by the amulet.
     * * Initializes the amulet with a predefined fear percentage and stores the affected enemies.
     */
    AKillerLook(std::vector<std::shared_ptr<Enemy>> e);

    /**
     * @brief Destructor for the AKillerLook class.
     * * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    ~AKillerLook() override;

    /**
     * @brief Applies the Killer Look Amulet's effect to the enemies.
     * * Reduces the damage of each enemy based on the player's level and the enemy's intelligence.
     * * @param p Reference to the Player object.
     */
    void use(Player& p) override;

    /**
     * @brief Gets the fear percentage of the amulet.
     * * @return unsigned int The fear percentage.
     */
    unsigned int getFearPercentage() const;

    /**
     * @brief Gets the description of the Killer Look Amulet's effect.
     * * @return std::string The description of the amulet.
     */
    std::string getKillerLookDescription() const;
};

#endif