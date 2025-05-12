//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "APerseverance.h"
#include "Player.h"

APerseverance::APerseverance() : Amulet(100, false, "perseverance", "If you are on the verge of death, \nyou have a second chance! \nBut don't be intoxicated by this power... \nBecause you have only one usage! \nthen you need to pay 50 gold.", 5)
{
    perseverance_description = "If you are on the verge of death, \nyou have a second chance! \nBut don't be intoxicated by this power... \nBecause you have only one usage, before you meet him...";
    additional_health = 100;
    was_used = false;
}

APerseverance::~APerseverance() {}

void APerseverance::use(Player& p)
{
    if (getWasUsed() == false)
    {
        if (p.getHealth() > 0 && p.getHealth() <= 30)
        {
            unsigned int new_health = additional_health;
            p.setHealth(new_health);
            setWasUsed(true);
        }
    }
}

unsigned int APerseverance::getAdditionalHealth() const
{
    return additional_health;
}

void APerseverance::setAdditionalHealth(unsigned int new_additional_health)
{
    additional_health = new_additional_health;
}

bool APerseverance::getWasUsed() const
{
    return was_used;
}

void APerseverance::setWasUsed(bool new_was_used)
{
    was_used = new_was_used;
}


