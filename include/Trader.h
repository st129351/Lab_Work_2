#ifndef TRADER_H
#define TRADER_H

#include "NPC.h"
#include <sstream>
#include <vector>
#include <memory>

class Amulet;
class Player;
class GameField;
class Enemy;
// forward declaration

class Trader : public NPC
{
private:
    std::shared_ptr<Amulet> killer_look;
    std::shared_ptr<Amulet> fear_death; 
    std::shared_ptr<Amulet> madness; 
    std::shared_ptr<Amulet> persev;
    std::shared_ptr<Amulet> best_exp;
    std::shared_ptr<Amulet> heal;
    std::shared_ptr<Amulet> dash;
    std::vector<std::shared_ptr<Amulet>> amulets;
    std::vector<std::shared_ptr<Enemy>> enemies;
    Player& player;
    GameField& field;
    bool speak_flag;
public:
    Trader(Player& p, GameField& f);
    ~Trader() override;

    void speak() override;
    std::string showStore();
};

#endif