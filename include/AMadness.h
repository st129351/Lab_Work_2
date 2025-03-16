#ifndef AMADNESS_H
#define AMADNESS_H

#include "Amulet.h"

class AMadness : public Amulet
{
private:
    unsigned int additional_damage;
    unsigned int side_effect;
    std::string madness_description; // help variable
    const unsigned int slots;
public:
    AMadness(Player& p);
    ~AMadness() override;

    void use(Player& p) override;
    void dont_use(Player& p) override;

    unsigned int getAdditionalDamage() const;
    void setAdditionalDamage(unsigned int new_additional_damage);

    unsigned int getSideEffect() const;
    void setSideEffect(unsigned int new_side_effect);

    unsigned int getSlots() const;
};

#endif