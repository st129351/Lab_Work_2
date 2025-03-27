#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Inventory.h"
#include "Fighter.h"

class NPC;
class Enemy;
class AFearOfDeath;
class YardDragon;
class Slime;
class Bandit;
class GameField;
// forward declaration

class Player : public Fighter
{
private:
    std::string name;
    unsigned int level;
    const unsigned int max_level;
    unsigned int exp;
    unsigned int gold;
    int x_pos;
    int y_pos;
    Inventory inventory;

    std::shared_ptr<AFearOfDeath> fear_death;

    struct AttackVisual
    {
        int x, y; // where was attack
    };
    std::vector<AttackVisual> attack_visuals; // vector for attack visuals

public:
    Player();
    
    void onDeath() override;
    void levelUp();

    std::string showInventory();

    void Buy(std::vector<std::shared_ptr<NPC>> npc_characters, char symb);
    void NPCSpeak(std::vector<std::shared_ptr<NPC>> npc_characters);
    void attackArea(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies);
    void UpdateAttackVisual(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies);

    // getters
    unsigned int getExp() const;
    unsigned int getGold() const;
    unsigned int getLevel() const;
    unsigned int getMaxLevel() const;
    std::string getName() const;
    int getX_pos() const;
    int getY_pos() const;
    // setters
    void setExp(unsigned int new_exp);
    void setGold(unsigned int new_gold);
    void setLevel(unsigned int new_level);
    void setName(const std::string& new_name);
    void setX_pos(unsigned int new_x_pos);
    void setY_pos(unsigned int new_y_pos);

};

#endif