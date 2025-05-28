#ifndef SLIME_H
#define SLIME_H

#include <iostream>
#include <chrono>

#include "Enemy.h"
#include <chrono>

class Player;
class GameField; // forward declaration

class Slime : public Enemy
{
private:
    unsigned int poison_damage;
    bool is_poisoning;
    std::chrono::system_clock::time_point poison_start; // when poison started
    const std::chrono::seconds poison_duration{3}; // how long poison will last
public:
    Slime(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player, unsigned int poizon_damage);
    ~Slime() = default;
    void onDeath() override;

    void applyPoison(Player& player);

    unsigned int getPoisonDamage() const;
    void setPoisonDamage(unsigned int new_poison_damage);

    void move(Player& player, GameField& field) override;
};

#endif