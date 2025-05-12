//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef ELDER_H
#define ELDER_H

#include "NPC.h"

/**
 * @class Elder
 * @brief Represents the Elder NPC in the game.
 *
 * The Elder class inherits from NPC and manages the Elder's specific behavior
 * and dialogue, including tracking the player's progress through missions.
 */
class Elder : public NPC
{
private:
    bool mission1; ///< Flag indicating the status of mission 1.
    bool mission2; ///< Flag indicating the status of mission 2.
    bool mission3; ///< Flag indicating the status of mission 3.

public:
    /**
     * @brief Constructor for the Elder class.
     *
     * Initializes the Elder with a name and description, and sets the initial
     * mission statuses.
     */
    Elder();

    /**
     * @brief Destructor for the Elder class.
     */
    ~Elder() override;

    /**
     * @brief Handles the Elder's dialogue.
     *
     * Overrides the speak() method from the NPC class to provide specific
     * dialogue based on the player's mission progress.
     */
    void speak() override;

    /**
     * @brief Gets the status of mission 1.
     *
     * @return true if mission 1 is active, false otherwise.
     */
    bool getMission1() const;

    /**
     * @brief Gets the status of mission 2.
     *
     * @return true if mission 2 is active, false otherwise.
     */
    bool getMission2() const;

    /**
     * @brief Gets the status of mission 3.
     *
     * @return true if mission 3 is active, false otherwise.
     */
    bool getMission3() const;

    /**
     * @brief Sets the status of mission 1.
     *
     * @param value The new status of mission 1.
     */
    void setMission1(bool value);

    /**
     * @brief Sets the status of mission 2.
     *
     * @param value The new status of mission 2.
     */
    void setMission2(bool value);

    /**
     * @brief Sets the status of mission 3.
     *
     * @param value The new status of mission 3.
     */
    void setMission3(bool value);
};

#endif