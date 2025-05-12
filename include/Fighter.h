//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <iostream>
#include <vector>

/**
 * @class Fighter
 * @brief Base class for all fighting characters in the game.
 *
 * The Fighter class provides common properties and functions for characters
 * that can engage in combat, such as health, damage, and attack capabilities.
 */
class Fighter
{
private:
    unsigned int health; ///< Current health of the fighter.
    unsigned int damage; ///< Attack damage of the fighter.
    std::string name; ///< Name of the fighter.

public:
    /**
     * @brief Constructor for the Fighter class.
     *
     * @param name   Name of the fighter.
     * @param health Initial health of the fighter.
     * @param damage Attack damage of the fighter.
     */
    Fighter(const std::string& name, unsigned int health, unsigned int damage);

    /**
     * @brief Virtual destructor for the Fighter class.
     *
     * Ensures proper cleanup of derived class objects.
     */
    virtual ~Fighter() {}

    /**
     * @brief Pure virtual function for handling death.
     *
     * Must be implemented in derived classes to define specific death behavior.
     */
    virtual void onDeath() = 0;

    /**
     * @brief Performs an attack on the target fighter.
     *
     * @param target The fighter to attack.
     */
    void attack(Fighter& target);

    /**
     * @brief Reduces the fighter's health by the given damage amount.
     *
     * @param damage The amount of damage to take.
     */
    void takeDamage(unsigned int damage);

    /**
     * @brief Checks if the fighter is still alive.
     *
     * @return true if health is greater than 0, false otherwise.
     */
    bool isAlive() const;

    /**
     * @brief Gets the name of the fighter.
     *
     * @return The name of the fighter.
     */
    std::string getName() const;

    /**
     * @brief Gets the attack damage of the fighter.
     *
     * @return The attack damage.
     */
    unsigned int getDamage() const;

    /**
     * @brief Gets the current health of the fighter.
     *
     * @return The current health.
     */
    unsigned int getHealth() const;

    /**
     * @brief Sets a new health value for the fighter.
     *
     * @param new_health The new health value.
     */
    void setHealth(unsigned int& new_health);

    /**
     * @brief Sets a new attack damage value for the fighter.
     *
     * @param new_damage The new damage value.
     */
    void setDamage(unsigned int& new_damage);

    /**
     * @brief Sets a new name for the fighter.
     *
     * @param new_name The new name.
     */
    void setName(const std::string& new_name);
};

#endif