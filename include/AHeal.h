#ifndef AHEALTH_H
#define AHEALTH_H

#include "Amulet.h"

class AHeal : public Amulet
{
private:
    unsigned int heal_value;
    std::string heal_description;
public:
    AHeal(Player& p);
    ~AHeal() override;

    void use(Player& p) override;
    
};

#endif