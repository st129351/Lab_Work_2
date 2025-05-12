//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @class NPC
 * @brief Base class for all Non-Player Characters (NPCs).
 *
 * This class provides a common structure and functionality for NPCs,
 * including name, description, position on the map, and dialogue state.
 */
class NPC
{
private:
    std::string name; ///< The name of the NPC.
    std::string description; ///< The description of the NPC.
    int x_pos; ///< The X-coordinate of the NPC's position on the map.
    int y_pos; ///< The Y-coordinate of the NPC's position on the map.
    bool dialogue_complete; ///< Flag indicating if the dialogue with the NPC is complete.

public:
    /**
     * @brief Constructor for the NPC class.
     *
     * Initializes a new NPC object with the given name and description.
     * The dialogue is initially set to incomplete.
     *
     * @param name The name of the NPC.
     * @param description The description of the NPC.
     */
    NPC(std::string name, std::string description);

    /**
     * @brief Virtual destructor for the NPC class.
     *
     * Ensures proper cleanup of NPC objects and their derived classes.
     */
    virtual ~NPC() = default;

    /**
     * @brief Abstract method to initiate dialogue with the NPC.
     *
     * Must be overridden in derived classes to implement specific
     * dialogue behavior.
     */
    virtual void speak() = 0;

    /**
     * @brief Gets the name of the NPC.
     *
     * @return The name of the NPC.
     */
    std::string getName() const;

    /**
     * @brief Gets the description of the NPC.
     *
     * @return The description of the NPC.
     */
    std::string getDescription() const;

    /**
     * @brief Checks if the dialogue with the NPC is complete.
     *
     * @return true if the dialogue is complete, false otherwise.
     */
    bool getDialogueComplete() const;

    /**
     * @brief Sets a new name for the NPC.
     *
     * @param new_name The new name of the NPC.
     */
    void setName(std::string new_name);

    /**
     * @brief Sets a new description for the NPC.
     *
     * @param new_description The new description of the NPC.
     */
    void setDescription(std::string new_description);

    /**
     * @brief Sets the dialogue completion status of the NPC.
     *
     * @param new_value The new value for the dialogue completion flag.
     */
    void setDialogueComplete(bool new_value);

    /**
     * @brief Gets the X-coordinate of the NPC's position.
     *
     * @return The X-coordinate of the NPC's position.
     */
    int getX_pos() const;

    /**
     * @brief Gets the Y-coordinate of the NPC's position.
     *
     * @return The Y-coordinate of the NPC's position.
     */
    int getY_pos() const;

    /**
     * @brief Sets the X-coordinate of the NPC's position.
     *
     * @param new_pos The new X-coordinate of the NPC's position.
     */
    void setX_pos(int new_pos);

    /**
     * @brief Sets the Y-coordinate of the NPC's position.
     *
     * @param new_pos The new Y-coordinate of the NPC's position.
     */
    void setY_pos(int new_pos);
};

#endif