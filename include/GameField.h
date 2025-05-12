//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include <memory>
#include <cctype> // to use fast checking for a number (isdigit)

class Player;
class Enemy;
class YardDragon;
class NPC;
class Elder;
class Trader;
// forward declaration

/**
 * @class GameField
 * @brief Represents the game field.
 *
 * The GameField class manages the game map, player, enemies, and NPCs.
 * It handles drawing the field, player movement, interactions, and combat.
 */
class GameField
{
private:
    char field[30][15]; ///< The 2D array representing the game field.
    Player& player; ///< Reference to the player.
    std::shared_ptr<YardDragon>& dragon; ///< Shared pointer to the YardDragon.
    std::shared_ptr<Elder> elder; ///< Shared pointer to the Elder NPC.
    std::shared_ptr<Trader> trader; ///< Shared pointer to the Trader NPC.
    std::vector<std::shared_ptr<NPC>> npc_characters; ///< Vector of shared pointers to NPCs.
    bool p_was_seen_d; ///< Flag indicating if the player was seen by the dragon.
    char input_symb; ///< Last input symbol.
protected:
    std::vector<std::shared_ptr<Enemy>> enemies; ///< Vector of shared pointers to enemies.
public:
    /**
     * @brief Constructor for the GameField class.
     *
     * Initializes the game field, player, and dragon.
     *
     * @param p Reference to the Player object.
     * @param d Shared pointer to the YardDragon object.
     */
    GameField(Player& p, std::shared_ptr<YardDragon>& d);

    /**
     * @brief Destructor for the GameField class.
     */
    ~GameField();

    /**
     * @brief Draws the game field.
     *
     * Outputs the current state of the game field to the console.
     */
    void draw() const;

    /**
     * @brief Gets the symbol at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return char The symbol at the specified coordinates.
     */
    char getSymbol(int x, int y) const;

    /**
     * @brief Sets the symbol at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param symbol The new symbol.
     */
    void setSymbol(int x, int y, char symbol);

    /**
     * @brief Gets the flag indicating if the player was seen by the dragon.
     *
     * @return bool The flag value.
     */
    bool getPWasSeenD() const;

    /**
     * @brief Sets the flag indicating if the player was seen by the dragon.
     *
     * @param new_value The new flag value.
     */
    void setPWasSeenD(bool new_value);

    /**
     * @brief Gets the last input symbol.
     *
     * @return char The last input symbol.
     */
    char getInputSymb() const;

    /**
     * @brief Sets the last input symbol.
     *
     * @param new_symb The new input symbol.
     */
    void setInputSymb(char new_symb);

    /**
     * @brief Gets the Elder NPC.
     *
     * @return std::shared_ptr<Elder> The Elder NPC.
     */
    std::shared_ptr<Elder> getElder();

    /**
     * @brief Spawns the player at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void playerSpawn(int x, int y);

    /**
     * @brief Spawns the YardDragon at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void yardDragonSpawn(int x, int y);

    /**
     * @brief Spawns the Elder NPC at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void elderSpawn(int x, int y);

    /**
     * @brief Spawns the Trader NPC at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void traderSpawn(int x, int y);

    /**
     * @brief Gets the YardDragon.
     *
     * @return YardDragon& The YardDragon.
     */
    YardDragon& getDragon();

    /**
     * @brief Spawns a Slime enemy at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void slimeSpawn(int x, int y);

    /**
     * @brief Spawns a Bandit enemy at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void banditSpawn(int x, int y);

    /**
     * @brief Checks for collision at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return bool True if there is a collision, false otherwise.
     */
    bool checkCollision(int x, int y);

    /**
     * @brief Checks if the player is within the dragon's attack range.
     *
     * @param x The x-coordinate of the dragon.
     * @param y The y-coordinate of the dragon.
     * @return bool True if the player is within range, false otherwise.
     */
    bool checkDragonRange(int x, int y);

    /**
     * @brief Handles combat between the player and enemies.
     */
    void combat();

    /**
     * @brief Handles buying items from a Trader.
     *
     * @param symb The symbol representing the item to buy.
     */
    void Buy(char symb);

    /**
     * @brief Handles player movement.
     *
     * @param where The direction to move ('w', 'a', 's', 'd').
     */
    void Movement(char where);

    /**
     * @brief Handles player interactions (e.g., speaking, showing inventory).
     *
     * @param what The type of interaction ('e', 'i').
     */
    void Interaction(char what);

    /**
     * @brief Gets the vector of enemies.
     *
     * @return std::vector<std::shared_ptr<Enemy>>& The vector of enemies.
     */
    std::vector<std::shared_ptr<Enemy>>& getEnemies();

    /**
     * @brief Gets the vector of NPCs.
     *
     * @return std::vector<std::shared_ptr<NPC>>& The vector of NPCs.
     */
    std::vector<std::shared_ptr<NPC>>& getNPC();

    /**
     * @brief Moves the enemies.
     */
    void moveEnemies();
};

#endif