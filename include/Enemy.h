#ifndef ENEMY_H
#define ENEMY_H

#include "Fighter.h"

class GameField;
class Player; // forward declarations 

class Enemy : public Fighter
{
private: 
    std::string enemy_description;
    unsigned int iq;
    int x_pos;
    int y_pos;
public:
    Enemy(std::string name, unsigned int health, unsigned int damage, unsigned int iq);
    virtual ~Enemy() = default;

    std::string getEnemyDescription() const;
    void setEnemyDescription(const std::string& new_enemy_description);

    unsigned int getIQ() const;
    void setIQ(unsigned int new_iq);

    virtual void move(Player& player, GameField& field) = 0;

    virtual int getX_pos() const;
    virtual int getY_pos() const;
    virtual void setX_pos(unsigned int new_x_pos);
    virtual void setY_pos(unsigned int new_y_pos);
};

#endif