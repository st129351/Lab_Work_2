#ifndef AFREAROFDEATH_H
#define AFREAROFDEATH_H

#include "Amulet.h"

class AFearOfDeath : public Amulet
{
private:
    unsigned int additional_damage;
    const unsigned int slots;
    std::string fear_of_death_description;
public:
    AFearOfDeath(Player& p);
    ~AFearOfDeath() override;
    
    void use(Player& p) override;
    void dont_use(Player& p) override;

    unsigned int getAdditionalDamage() const;
    void setAdditionalDamage(unsigned int new_additional_damage);

    unsigned int getSlots() const;
};

#endif