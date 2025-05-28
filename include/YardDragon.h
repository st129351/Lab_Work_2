#ifndef YARDDRAGON_H
#define YARDDRAGON_H

#include "Enemy.h"
#include <iostream>
#include <string>
#include <vector>

class Player;
class GameField;
// not suitable, when using the object of class (now ptr in constructor)

class YardDragon : public Enemy
{
private:
    int attack_range;
    bool can_move;
    int fire_count; // update in general game circle
    struct FireVisual
    {
        int x, y;
    };
    std::vector<FireVisual> fire_visuals;

public:
    YardDragon(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player, int attack_range);
    ~YardDragon() = default;
    void onDeath() override;

    void FireAttack(GameField& field, Player& player);
    void UpdateFireVisual(GameField& field, Player& player);

    unsigned int getAttackRange() const;
    void setAttackRange(int new_range);
    int getFireCount() const;
    void setFireCount(int new_value);
    bool getCanMove() const;
    void setCanMove(bool new_value);

    void move(Player& player, GameField& field) override;
};

#endif