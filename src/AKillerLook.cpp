#include "AKillerLook.h"
#include "Player.h"
#include "Enemy.h"

AKillerLook::AKillerLook(Enemy& e) : Amulet(105, false, "killer look", "Your enemies will tremble at the knees \njust looking at you", 5), fear_percentage(15)
{
    killer_look_description = "Your enemies will tremble at the knees \njust looking at you";
}

AKillerLook::~AKillerLook() {}

void AKillerLook::use(Player& p)
{
    for (Enemy* enemy : enemies)
    {
        unsigned int percent = fear_percentage * p.getLevel();
        unsigned int value = enemy->getDamage() - enemy->getIQ() * percent / 100;
        enemy->setDamage(value);
    }
}

void AKillerLook::dont_use(Player& p)
{
    for (Enemy* enemy : enemies)
    {
        unsigned int percent = fear_percentage * p.getLevel();
        unsigned int value = enemy->getDamage() + enemy->getIQ() * percent / 100;
        enemy->setDamage(value);
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
