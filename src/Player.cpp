#include "Player.h"
#include "Enemy.h"
#include "GameField.h"
#include "Bandit.h"
#include "Slime.h"
#include "YardDragon.h"
#include "Fighter.h"
#include "NPC.h"
#include "AFearOfDeath.h"
#include "Amulet.h"
#include "AKillerLook.h"
#include "AMadness.h"
#include "APerseverance.h"
#include "BestExp.h"
#include "AHeal.h"
#include "ADash.h"

Player::Player(): Fighter("", 100, 10), max_level(3), inventory(*this)
{
    this->level = 1;
    this->exp = 0;
    this->gold = 100;
    this->x_pos = 14;  // начальная позиция x
    this->y_pos = 13;   // начальная позиция y (центр по вертикали)
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Enter the name of your hero: ";
    std::cin.ignore(); // clear buffer, if \n
    std::getline(std::cin, name);
    setName(name);
    persev_flag = false;
    best_exp_flag = false;
    heal_flag = false;
    dash_flag = false;

    killer_look = nullptr;
    fear_death = nullptr;
    madness = nullptr;
    persev = nullptr;
    best_exp = nullptr;
    heal = nullptr;
    dash = nullptr;
}

void Player::onDeath()
{
    unsigned int new_health = 0;
    setHealth(new_health);
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Game over! You are dead 💀" << std::endl;
}

void Player::levelUp()
{
    if (level < max_level)
    {
        setLevel(getLevel() + 1);
        setExp(0);
        setGold(getGold() + level * 10);

        unsigned int new_damage = getDamage() + 4;
        setDamage(new_damage);

        unsigned int new_health = getHealth() + 8;
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
bool Player::getPersevFlag() const
{
    return persev_flag;
}

bool Player::getBestExpFlag() const
{
    return best_exp_flag;
}

bool Player::getHealFlag() const
{
    return heal_flag;
}

bool Player::getDashFlag() const
{
    return dash_flag;
}

std::shared_ptr<APerseverance> Player::getPersev()
{
    return persev;
}

std::shared_ptr<BestExp> Player::getBestExp()
{
    return best_exp;
}

std::shared_ptr<AHeal> Player::getHeal() 
{
    return heal;
}

std::shared_ptr<ADash> Player::getDash()
{
    return dash;
}

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

int Player::getX_pos() const
{
    return x_pos;
}

int Player::getY_pos() const
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

            char simb = field.getSymbol(attack_x, attack_y);
            if (simb != '#' && simb != 's' && simb != 'Y' && simb != 'b' && simb != 'E' && simb != 'T')
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
                    // for different enemies
                    if (auto dragon = std::dynamic_pointer_cast<YardDragon> (enemy))
                    {
                        field.setSymbol(i->x, i->y, 'Y');
                        flag = true;
                    }
                    if (auto slime = std::dynamic_pointer_cast<Slime> (enemy)) 
                    { // dynamic_pointer_cast return nullptr if type conversion is impossible
                        field.setSymbol(i->x, i->y, 's');
                        flag = true;
                    }
                    if (auto bandit = std::dynamic_pointer_cast<Bandit> (enemy))
                    {
                        field.setSymbol(i->x, i->y, 'b');
                        flag = true;
                    }
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

void Player::NPCSpeak(std::vector<std::shared_ptr<NPC>> npc_characters)
{
    for (int ax = -1; ax < 2; ax++)
    {
        for (int ay = -1; ay < 2; ay++)
        {
            if (ax == 0 && ay == 0) continue;

            int posX = x_pos + ax;
            int posY = y_pos + ay;
            for (auto& npc : npc_characters)
            {
                if (npc->getX_pos() == posX && npc->getY_pos() == posY)
                {
                    npc->speak(); 
                }
            }
        }
    }
}

void Player::Buy(std::vector<std::shared_ptr<NPC>> npc_characters, char symb, GameField& field)
{
    int num = symb - '0'; // symb to number by ASCII (0 has code 48, able to converct symb 1-9 to number)
    if (num > 7) // only 6 amulets
    {
        std::cout << "incorrect index of amulet!" << std::endl;
        return;
    }
    for (int ax = -1; ax < 2; ax++)
    {
        for (int ay = -1; ay < 2; ay++)
        {
            if (ax == 0 && ay == 0) continue;

            int posX = x_pos + ax;
            int posY = y_pos + ay;
            for (auto& npc : npc_characters)
            {
                if (npc->getX_pos() == posX && npc->getY_pos() == posY)
                {
                    if (num == 1 && fear_death == nullptr)
                    {
                        fear_death = std::make_shared<AFearOfDeath> (*this);
                        if (fear_death->getCost() <= getGold())
                        {
                            int new_gold = getGold() - fear_death->getCost();
                            setGold(new_gold);
                            fear_death->use(*this);
                            fear_death->setUsage(true);
                            std::shared_ptr<Amulet> amulet = fear_death;
                            inventory.add(amulet);
                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 1 && fear_death != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }

                    if (num == 2 && killer_look == nullptr)
                    {
                        enemies = field.getEnemies();
                        killer_look = std::make_shared<AKillerLook> (enemies);

                        if (killer_look->getCost() <= getGold())
                        {
                            int new_gold = getGold() - killer_look->getCost();
                            setGold(new_gold);
                            killer_look->use(*this);
                            killer_look->setUsage(true);
                            std::shared_ptr<Amulet> amulet = killer_look;
                            inventory.add(amulet);
                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 2 && killer_look != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }

                    if (num == 3 && madness == nullptr)
                    {
                        madness = std::make_shared<AMadness> (*this);
                        if (madness->getCost() <= getGold())
                        {
                            int new_gold = getGold() - madness->getCost();
                            setGold(new_gold);
                            madness->use(*this);
                            madness->setUsage(true);
                            std::shared_ptr<Amulet> amulet = madness;
                            inventory.add(amulet);                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 3 && madness != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }

                    if (num == 4 && persev == nullptr)
                    {
                        persev = std::make_shared<APerseverance> ();
                        if (persev->getCost() <= getGold())
                        {
                            int new_gold = getGold() - persev->getCost();
                            setGold(new_gold);
                            // persev->use(*this);
                            persev->setUsage(true);
                            persev_flag = true;
                            std::shared_ptr<Amulet> amulet = persev;
                            inventory.add(amulet);                        
                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 4 && persev != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }

                    if (num == 5 && best_exp == nullptr)
                    {
                        best_exp = std::make_shared<BestExp> (*this);
                        if (best_exp->getCost() <= getGold())
                        {
                            int new_gold = getGold() - best_exp->getCost();
                            setGold(new_gold);
                            best_exp_flag = true;
                            best_exp->setUsage(true);
                            std::shared_ptr<Amulet> amulet = best_exp;
                            inventory.add(amulet);                        
                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 5 && best_exp != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }

                    if (num == 6 && heal == nullptr)
                    {
                        heal = std::make_shared<AHeal> ();
                        if (heal->getCost() <= getGold())
                        {
                            int new_gold = getGold() - heal->getCost();
                            setGold(new_gold);
                            heal_flag = true;
                            heal->setUsage(true);
                            std::shared_ptr<Amulet> amulet = heal;
                            inventory.add(amulet);
                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 6 && heal != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }

                    if (num == 7 && dash == nullptr)
                    {
                        dash = std::make_shared<ADash> (field);
                        if (dash->getCost() <= getGold())
                        {
                            int new_gold = getGold() - dash->getCost();
                            setGold(new_gold);
                            dash_flag = true;
                            dash->setUsage(true);
                            std::shared_ptr<Amulet> amulet = dash;
                            inventory.add(amulet);                        
                        }
                        else
                        {
                            std::cout << "insufficient funds :(";
                        }
                    }
                    else if (num == 7 && dash != nullptr)
                    {
                        std::cout << "This amulet is already on!" << std::endl;
                    }
                }
            }
        }
    }
}

