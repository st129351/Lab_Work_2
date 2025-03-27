#ifndef TRADER_H
#define TRADER_H

#include "NPC.h"
#include <sstream>
#include <vector>
#include <memory>

class Amulet;
class Player;
// forward declaration

class Trader : public NPC
{
private:
    std::shared_ptr<Amulet> fear_death;  
    std::vector<std::shared_ptr<Amulet>> amulets;
    Player& player;
    bool speak_flag;
public:
    Trader(Player& p);
    ~Trader() override;

    void speak() override;
    std::string showStore();
};

#endif