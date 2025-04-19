#include "AHeal.h"
#include "Player.h"

AHeal::AHeal() : Amulet(15, false, "heal", "great healing power", 5)
{
    heal_description = "great healing power";
    heal_value = 1;
}

AHeal::~AHeal() {}

void AHeal::use(Player& p)
{
    unsigned int new_health1 = p.getHealth() + heal_value;
    unsigned int new_health2 = 100;
    if (p.getHealth() < 100)
    {
        if (p.getHealth() > 95)
        {
            p.setHealth(new_health2);
        }
        else
        {
            p.setHealth(new_health1);
        }
    }
    else
    {
        return;
    }
}

unsigned int AHeal::getHealValue() const
{
    return heal_value;
}

void AHeal::setHealValue(unsigned int new_value)
{
    heal_value = new_value;
}
