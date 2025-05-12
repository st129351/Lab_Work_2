//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "AFearOfDeath.h"   

AFearOfDeath::AFearOfDeath(Player& p) : Amulet(35, false, "fear of death", "increase damage by 50%", 2)
{
    additional_damage = p.getDamage() * 0.5;
    fear_of_death_description = "increase damage by 50%";
}

AFearOfDeath::~AFearOfDeath() {}

void AFearOfDeath::use(Player& p)
{
    unsigned int new_damage = p.getDamage() + additional_damage;
    p.setDamage(new_damage);
}

unsigned int AFearOfDeath::getAdditionalDamage() const
{
    return additional_damage;
}

void AFearOfDeath::setAdditionalDamage(unsigned int new_additional_damage)
{
    additional_damage = new_additional_damage;
}