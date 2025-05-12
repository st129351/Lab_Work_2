//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include <cmath>
#include "AKillerLook.h"
#include "Player.h"
#include "Enemy.h"
#include "GameField.h"

AKillerLook::AKillerLook(std::vector<std::shared_ptr<Enemy>> e) : Amulet(105, false, "killer look", "Your enemies will tremble at the knees \njust looking at you", 5), fear_percentage(15), enemies(e)
{
    killer_look_description = "Your enemies will tremblue at the knees \njust looking at you";
}

AKillerLook::~AKillerLook() {}

void AKillerLook::use(Player& p)
{
    for (std::shared_ptr<Enemy> enemy : enemies)
    {
        unsigned int percent = fear_percentage * p.getLevel();
        unsigned int reduce = std::floor(enemy->getIQ() * percent / 100);
        if (reduce > enemy->getDamage())
        {
            unsigned int value = 1;
            enemy->setDamage(value);
        }
        else
        {
            unsigned int value = enemy->getDamage() - reduce;
            enemy->setDamage(value);
        }
    }
}

unsigned int AKillerLook::getFearPercentage() const
{
    return fear_percentage;
}

std::string AKillerLook::getKillerLookDescription() const
{
    return killer_look_description;
}
