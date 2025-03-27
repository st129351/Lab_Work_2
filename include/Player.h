#ifndef PLAYER_H
#define PLAYER_H

#include "Fighter.h"
#include "Inventory.h"
#include "Amulet.h"
#include <string>
#include <vector>
#include "Enemy.h"
#include "GameField.h"
#include <memory>

class Player : public Fighter
{
private:
    std::string name;
    unsigned int level;
    const unsigned int max_level;
    unsigned int exp;
    unsigned int gold;
    unsigned int x_pos;
    unsigned int y_pos;
    Inventory inventory;

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

    void attackArea(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies);
    void UpdateAttackVisual(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies);

    // getters
    unsigned int getExp() const;
    unsigned int getGold() const;
    unsigned int getLevel() const;
    unsigned int getMaxLevel() const;
    std::string getName() const;
    unsigned int getX_pos() const;
    unsigned int getY_pos() const;
    // setters
    void setExp(unsigned int new_exp);
    void setGold(unsigned int new_gold);
    void setLevel(unsigned int new_level);
    void setName(const std::string& new_name);
    void setX_pos(unsigned int new_x_pos);
    void setY_pos(unsigned int new_y_pos);

};

#endif