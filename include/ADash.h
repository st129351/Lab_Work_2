#ifndef ADASH_H
#define ADASH_H

#include "Amulet.h"
#include <vector>

class GameField;
class Player;

/**
 * @class ADash
 * @brief Class representing the Dash Amulet in the game.
 * * The Dash Amulet allows the player to quickly move a short distance in a specified direction.
 */
class ADash : public Amulet
{
private:
    GameField* field; ///< Pointer to the GameField object.
    /**
     * @struct DashVisual
     * @brief Structure for storing coordinates of dash visual effects.
     */
    struct DashVisual
    {
        int x, y; ///< Coordinates of dash effect on the game field.
    };
    std::vector<DashVisual> dash_visual; ///< Vector of dash visual effects.
public:
    /**
     * @brief Constructor for testing purposes.
     * * Initializes the ADash object with default values and a null GameField pointer.
     */
    ADash();

    /**
     * @brief Constructor for the ADash class.
     * * Initializes the ADash object with a reference to the GameField.
     * * @param f Reference to the GameField object.
     */
    ADash(GameField& f);

    /**
     * @brief Destructor for the ADash class.
     * * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    ~ADash() override;

    /**
     * @brief Updates the visual effects of the dash on the game field.
     * * Clears the previous dash visual symbols from the field.
     */
    void UpdateDashVisual();

    /**
     * @brief Applies the Dash Amulet's effect to the player.
     * * Moves the player in the specified direction if possible.
     * * @param player Reference to the Player object.
     */
    void use(Player& player) override;
};

#endif