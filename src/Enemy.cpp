#include "Enemy.h"
#include "GameField.h"
#include "Player.h"

Enemy::Enemy(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player) : Fighter(name, health, damage)
{
    this->iq = iq;
    this->exp = exp;
    this->player = player;
}

std::string Enemy::getEnemyDescription() const
{
    return enemy_description;
}

void Enemy::setEnemyDescription(const std::string& new_enemy_description)
{
    enemy_description = new_enemy_description;
}

unsigned int Enemy::getIQ() const
{
    return iq;
}

void Enemy::setIQ(unsigned int new_iq)
{
    iq = new_iq;
}

unsigned int Enemy::getExp() const
{
    return exp;
}

void Enemy::setExp(unsigned int new_exp)
{
    exp = new_exp;
}

Player& Enemy::getPlayer()
{
    return *player;
}

void Enemy::setPlayer(Player* new_player)
{
    player = new_player;
}

int Enemy::getX_pos() const
{
    return x_pos;
}

int Enemy::getY_pos() const
{
    return y_pos;
}

void Enemy::setX_pos(unsigned int new_x_pos)
{
    x_pos = new_x_pos;
}

void Enemy::setY_pos(unsigned int new_y_pos)
{
    y_pos = new_y_pos;
}