#ifndef AFREAROFDEATH_H
#define AFREAROFDEATH_H

#include "Amulet.h"
#include "Player.h"

class AFearOfDeath : public Amulet
{
private:
    unsigned int additional_damage;
    std::string fear_of_death_description;
public:
    AFearOfDeath(Player& p);
    ~AFearOfDeath() override;
    
    void use(Player& p) override;

    unsigned int getAdditionalDamage() const;
    void setAdditionalDamage(unsigned int new_additional_damage);
};

#endif