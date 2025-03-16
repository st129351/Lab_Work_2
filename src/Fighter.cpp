#include "Fighter.h"

Fighter::Fighter(const std::string& name, unsigned int health, unsigned int damage)
{
    this->name = name;
    this->damage = damage;
    this->health = health;
}

std::string Fighter::getName() const
{
    return name;
}

unsigned int Fighter::getHealth() const
{
    return health;
}

unsigned int Fighter::getDamage() const
{
    return damage;
}

void Fighter::setHealth(unsigned int& new_health)
{
    health = new_health;
}

void Fighter::setDamage(unsigned int& new_damage)
{
    damage = new_damage;
}

void Fighter::setName(const std::string& new_name)
{
    name = new_name;
}

bool Fighter::isAlive() const
{
    return health > 0;
}

void Fighter::takeDamage(unsigned int damage)
{
    if (damage >= health)
    {
        health = 0;
        onDeath();
    }
    else
    {
        health -= damage;
    }
}

void Fighter::attack(Fighter& target)
{
    target.takeDamage(damage);
}

