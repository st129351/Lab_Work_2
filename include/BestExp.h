//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef BESTEXP_H
#define BESTEXP_H

#include "Amulet.h"

class Player;

/**
 * @class BestExp
 * @brief Represents an amulet that increases experience gain for the player.
 *
 * The BestExp class inherits from Amulet and provides functionality to increase
 * the player's experience points with each step.
 */
class BestExp : public Amulet
{
private:
    unsigned int add_exp; ///< The amount of experience to add per step.
    std::string best_exp_description; ///< Description of the BestExp amulet.

public:
    /**
     * @brief Constructor for the BestExp class.
     *
     * @param p Reference to the Player object.
     */
    BestExp(Player& p);

    /**
     * @brief Destructor for the BestExp class.
     */
    ~BestExp() override;

    /**
     * @brief Gets the amount of experience added per step.
     *
     * @return The amount of experience added.
     */
    unsigned int getAddExp() const;

    /**
     * @brief Sets the amount of experience added per step.
     *
     * @param new_exp The new amount of experience to add.
     */
    void setAddExp(unsigned int new_exp);

    /**
     * @brief Uses the amulet to increase the player's experience.
     *
     * @param p Reference to the Player object.
     */
    void use(Player& p) override;
};

#endif