#include "APerseverance.h"
#include "Player.h"

APerseverance::APerseverance() : Amulet(100, false, "perseverance", "If you are on the verge of death, \nyou have a second chance! \nBut don't be intoxicated by this power... \nBecause you have only one usage! \nthen you need to pay 50 gold.", 5)
{
    perseverance_description = "If you are on the verge of death, \nyou have a second chance! \nBut don't be intoxicated by this power... \nBecause you have only one usage! \nthen you need to pay 50 gold.";
    additional_health = 100;
    was_used = false;
}

APerseverance::~APerseverance() {}

void APerseverance::use(Player& p)
{
    if (getWasUsed() == false)
    {
        if (0 < p.getHealth() && p.getHealth() <= 20)
        {
            unsigned int new_health = additional_health - p.getHealth();
            p.setHealth(new_health);
            setWasUsed(true);
        }
        if (p.getHealth() <= 0)
        {
            unsigned int new_health = additional_health;
            p.setHealth(new_health);
            setWasUsed(true);
        }
    }
    else
    {
        warning();
    }
}

void APerseverance::warning()
{
    std::cout << "Firstly, you need to go to the blacksmith and..." << std::endl;
}

void APerseverance::dont_use(Player& p)
{
    return;
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


