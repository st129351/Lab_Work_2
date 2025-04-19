#ifndef AHEALTH_H
#define AHEALTH_H

#include "Amulet.h"

class Player;

class AHeal : public Amulet
{
private:
    unsigned int heal_value;
    std::string heal_description;
public:
    AHeal();
    ~AHeal() override;

    void use(Player& p) override;

    unsigned int getHealValue() const;
    void setHealValue(unsigned int new_value);
};

#endif