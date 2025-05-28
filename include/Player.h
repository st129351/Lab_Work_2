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
class AKillerLook;
class AMadness;
class APerseverance;
class BestExp;
class AHeal;
class ADash;
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
    bool persev_flag;
    bool best_exp_flag;
    bool heal_flag;
    bool dash_flag;
    Inventory inventory;
    std::vector<std::shared_ptr<Enemy>> enemies;

    std::shared_ptr<AFearOfDeath> fear_death;
    std::shared_ptr<AKillerLook> killer_look;
    std::shared_ptr<AMadness> madness;
    std::shared_ptr<APerseverance> persev;
    std::shared_ptr<BestExp> best_exp;
    std::shared_ptr<AHeal> heal;
    std::shared_ptr<ADash> dash;
    
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

    void Buy(std::vector<std::shared_ptr<NPC>> npc_characters, char symb, GameField& field);
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
    bool getPersevFlag() const;
    bool getBestExpFlag() const;
    bool getHealFlag() const;
    bool getDashFlag() const;
    std::shared_ptr<APerseverance> getPersev();
    std::shared_ptr<BestExp> getBestExp();
    std::shared_ptr<AHeal> getHeal();
    std::shared_ptr<ADash> getDash();
    // setters
    void setExp(unsigned int new_exp);
    void setGold(unsigned int new_gold);
    void setLevel(unsigned int new_level);
    void setName(const std::string& new_name);
    void setX_pos(unsigned int new_x_pos);
    void setY_pos(unsigned int new_y_pos);

};

#endif