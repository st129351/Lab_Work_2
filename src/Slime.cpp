#include "Slime.h"
#include "Player.h"
#include "GameField.h"

Slime::Slime(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player, unsigned int poizon_damage) 
: Enemy(name, health, damage, iq, exp, player)
{
    this->poison_damage = 3;
    this->is_poisoning = false;
}

void Slime::onDeath()
{
    Player& curr_player = this->getPlayer();
    unsigned int new_exp = curr_player.getExp() + this->getExp();
    curr_player.setExp(new_exp);
    unsigned int new_gold = curr_player.getGold() + this->getExp() * 2;
    curr_player.setGold(new_gold);
    std::cout << "Slime is dead 💥" << std::endl;
}

unsigned int Slime::getPoisonDamage() const
{
    return poison_damage;
}

void Slime::setPoisonDamage(unsigned int new_poison_damage)
{
    poison_damage = new_poison_damage;
}

void Slime::applyPoison(Player& player)
{
    if (!is_poisoning)
    {
        is_poisoning = true;
        poison_start = std::chrono::system_clock::now(); // now is poison start
        player.takeDamage(poison_damage);
    }
    else
    {
        auto curr_time = std::chrono::system_clock::now();
        // take duration in the form of std::chrono::duration (cast to seconds)
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(curr_time - poison_start);
        
        if (elapsed_time < poison_duration)
        {
            player.takeDamage(poison_damage);
        }
        else
        {
            is_poisoning = false;
        }
    }
    
}


void Slime::move(Player& player, GameField& field)
{
    int player_x = player.getX_pos();
    int player_y = player.getY_pos();

    int dist_x = player_x - this->getX_pos();
    int dist_y = player_y - this->getY_pos();

    int new_x = this->getX_pos();
    int new_y = this->getY_pos();

    if (!field.checkCollision(this->getX_pos(), this->getY_pos()) && dist_x <= 6 && dist_y <= 6)
    {
        if (abs(dist_x) > abs(dist_y))
        {
            if (this->getX_pos() > player_x)
            {
                new_x--;
            }
            else
            {
                new_x++;
            }
        }
        if (abs(dist_x) < abs(dist_y))
        {
            if (this->getY_pos() > player_y)
            {
                new_y--;
            }
            else
            {
                new_y++;
            }
        }
        if (abs(dist_x) == abs(dist_y))
        {
            if (this->getX_pos() > player_x)
            {
                new_x--;
            }
            else
            {
                new_x++;
            }
        }
        if (field.getSymbol(new_x, new_y) != '#' && field.getSymbol(new_x, new_y) != 'E' && field.getSymbol(new_x, new_y) != 'T' && field.getSymbol(new_x, new_y) != 's' && field.getSymbol(new_x, new_y) != 'b' && field.getSymbol(new_x, new_y) != 'Y' && field.getSymbol(new_x, new_y) != '@')
        {
            field.setSymbol(this->getX_pos(), this->getY_pos(), ' ');
            this->setX_pos(new_x);
            this->setY_pos(new_y);
            field.setSymbol(this->getX_pos(), this->getY_pos(), 's');
        }
    }
}
