#include "AMadness.h"
#include "Player.h"

AMadness::AMadness(Player& p) : Amulet(50, false, "madness", "increase damage by 100%, but has side effect, be careful!", 3)
{
    additional_damage = p.getDamage() * 1;
    side_effect = p.getHealth() * 0.5;
    madness_description = "increase damage by 100%, but has side effect, be careful!";
}

AMadness::~AMadness() {}

void AMadness::use(Player& p)
{
    unsigned int new_damage = p.getDamage() + additional_damage;
    p.setDamage(new_damage);
    unsigned int new_health = p.getHealth() - side_effect;
    p.setHealth(new_health);
}

void AMadness::dont_use(Player& p)
{
    unsigned int new_damage = p.getDamage() - additional_damage;
    p.setDamage(new_damage);
    unsigned int new_health = p.getHealth() + side_effect;
    p.setHealth(new_health);
}

unsigned int AMadness::getAdditionalDamage() const
{
    return additional_damage;
}

void AMadness::setAdditionalDamage(unsigned int new_additional_damage)
{
    additional_damage = new_additional_damage;
}

unsigned int AMadness::getSideEffect() const
{
    return side_effect;
}

void AMadness::setSideEffect(unsigned int new_side_effect)
{
    side_effect = new_side_effect;
}


