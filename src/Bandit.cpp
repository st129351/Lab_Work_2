#include "Bandit.h"
#include "Player.h"
#include "GameField.h"

Bandit::Bandit(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player) : Enemy(name, health, damage, iq, exp, player) {}

void Bandit::onDeath()
{
    Player& curr_player = this->getPlayer();
    unsigned int new_exp = curr_player.getExp() + this->getExp();
    curr_player.setExp(new_exp);
    // this->getPlayer().setExp(this->getExp() + this->getPlayer().getExp());
    std::cout << "Bandit was defeated!" << std::endl;
}

void Bandit::move(Player& player, GameField& field)
{
    int player_x = player.getX_pos();
    int player_y = player.getY_pos();

    int dist_x = player_x - this->getX_pos();
    int dist_y = player_y - this->getY_pos();

    int new_x = this->getX_pos();
    int new_y = this->getY_pos();

    if (!field.checkCollision(this->getX_pos(), this->getY_pos()))
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
        if (field.getSymbol(new_x, new_y) != '#' && field.getSymbol(new_x, new_y) != 's' && field.getSymbol(new_x, new_y) != 'b' && field.getSymbol(new_x, new_y) != 'Y' && field.getSymbol(new_x, new_y) != '@')
        {
            field.setSymbol(this->getX_pos(), this->getY_pos(), ' ');
            this->setX_pos(new_x);
            this->setY_pos(new_y);
            field.setSymbol(this->getX_pos(), this->getY_pos(), 'b');
        }
    }
}