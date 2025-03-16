#include "Player.h"

Player::Player(): Fighter("", 100, 10), max_level(3), inventory(*this)
{
    this->level = 1;
    this->exp = 0;
    this->gold = 0;
    this->x_pos = 14;  // начальная позиция x
    this->y_pos = 13;   // начальная позиция y (центр по вертикали)
    std::cout << "Enter the name of your hero: ";
    std::cin >> name;
    setName(name);
}

void Player::onDeath()
{
    unsigned int new_health = 0;
    setHealth(new_health);
    std::cout << "Game over! You are dead 💀" << std::endl;
}

void Player::levelUp()
{
    if (level < max_level)
    {
        setLevel(getLevel() + 1);
        setExp(0);
        setGold(getGold() + level * 10);

        unsigned int new_damage = getDamage() + 10;
        setDamage(new_damage);

        unsigned int new_health = getHealth() + 15;
        setHealth(new_health);

        std::cout << "You are level up! 🔥" << std::endl;
    }
}

std::string Player::showInventory()
{
    std::cout << "INVENTORY" << std::endl;
    return inventory.show();
}

// getters 
unsigned int Player::getExp() const
{
    return exp;
}

unsigned int Player::getGold() const
{
    return gold;
}

unsigned int Player::getLevel() const
{
    return level;
}

unsigned int Player::getMaxLevel() const
{
    return max_level;
}

std::string Player::getName() const
{
    return name;
}

// setters
void Player::setExp(unsigned int new_exp)
{
    exp = new_exp;
}

void Player::setGold(unsigned int new_gold)
{
    gold = new_gold;
}

void Player::setLevel(unsigned int new_level)
{
    level = new_level;
}

void Player::setName(const std::string& new_name)
{
    name = new_name;
}

unsigned int Player::getX_pos() const
{
    return x_pos;
}

unsigned int Player::getY_pos() const
{
    return y_pos;
}

void Player::setX_pos(unsigned int new_x_pos)
{
    x_pos = new_x_pos;
}

void Player::setY_pos(unsigned int new_y_pos)
{
    y_pos = new_y_pos;
}

void Player::attackArea(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies)
{
    // add attack visual
    // check 8 cells around player
    for (int ax = -1; ax < 2; ax++)
    {
        for (int ay = -1; ay < 2; ay++)
        {
            // pass by if its player
            if (ax == 0 && ay == 0) continue;

            int attack_x = x_pos + ax; // where will be attack
            int attack_y = y_pos + ay; // and its too

            if (field.getSymbol(attack_x, attack_y) != '#')
            {
                attack_visuals.push_back({attack_x, attack_y}); // add attack visual item to vector
                field.setSymbol(attack_x, attack_y, '*');
            }

            for (auto& enemy : enemies)
            {
                if (enemy->getX_pos() == attack_x && enemy->getY_pos() == attack_y)
                {
                    enemy->takeDamage(getDamage());
                }
            }
        }
    }
}

void Player::UpdateAttackVisual(GameField& field, std::vector<std::shared_ptr<Enemy>>& enemies)
{
    // earse attack visuals if time is up
    for (auto i = attack_visuals.begin(); i != attack_visuals.end();)
    // from begin vector to end 
    {
        if (field.getSymbol(i->x, i->y) == '*')
        {
            bool flag = false;
            for (auto& enemy : enemies)
            {
                if (enemy->getX_pos() == i->x && enemy->getY_pos() == i->y)
                {
                    field.setSymbol(i->x, i->y, '~');
                    flag = true;
                }
            }
            if (!flag)
            {
                field.setSymbol(i->x, i->y, ' ');
            }
        }
        i = attack_visuals.erase(i); // erase the element if time is up
    // go to next element (iteration) of vector with erase
    // check will be in every iteration of cycle (while in main.cpp)
    }
}

