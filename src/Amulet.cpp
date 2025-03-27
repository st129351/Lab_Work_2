#include "Amulet.h"
#include "Player.h"
// full including

Amulet::Amulet(unsigned int cost, bool usage, std::string name, std::string description, unsigned int slots)
{
    this->slots = slots;
    this->cost = cost;
    this->usage = usage;
    this->name = name;
    this->description = description;
}

unsigned int Amulet::getCost() const
{
    return cost;
}

bool Amulet::getUsage() const
{
    return usage;
}

unsigned int Amulet::getSlots() const
{
    return slots;
}

void Amulet::setSlots(unsigned int new_slots)
{
    slots = new_slots;
}

void Amulet::setCost(unsigned int new_cost)
{
    cost = new_cost;
}

void Amulet::setUsage(bool new_usage)
{
    usage = new_usage;
}

std::string Amulet::getName() const
{
    return name;
}

std::string Amulet::getDescription() const
{
    return description;
}

void Amulet::setName(std::string new_name)
{
    name = new_name;
}

void Amulet::setDescription(std::string new_description)
{
    description = new_description;
}

