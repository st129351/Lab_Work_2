#ifndef BANDIT_H
#define BANDIT_H

#include "Enemy.h"

class Player;
class GameField;
// forwad declaration

class Bandit : public Enemy
{
public:
    Bandit(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player);
    ~Bandit() = default;

    void onDeath() override;
    void move(Player& player, GameField& field) override;
};

#endif