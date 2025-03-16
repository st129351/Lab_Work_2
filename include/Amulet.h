#ifndef AMULET_H
#define AMULET_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Amulet
{
private:
    unsigned int cost;
    bool usage;
    std::string name;
    std::string description;
public:
    Amulet(unsigned int cost, bool usage, std::string name, std::string description);
    virtual ~Amulet() = default;

    virtual void use(Player& player) = 0;
    // redefinition in different amulets
    // = 0 - pure virtual func (not realise in base class)
    virtual void dont_use(Player& player) = 0;
    unsigned int getCost() const;
    bool getUsage() const;
    std::string getName() const;
    std::string getDescription() const;

    void setCost(unsigned int new_cost);
    void setUsage(bool new_usage);
    void setName(std::string new_name);
    void setDescription(std::string new_description);
};

#endif