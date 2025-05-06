//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "YardDragon.h"
#include "Player.h"
#include "GameField.h"

YardDragon::YardDragon(std::string name, unsigned int health, unsigned int damage, unsigned int iq, unsigned int exp, Player* player, int attack_range)
: Enemy(name, health, damage, iq, exp, player)
{
    this->fire_count = 0;
    this->can_move = true;
    this->attack_range = attack_range;
}

void YardDragon::onDeath()
{
    // static - save value of var between come into func
    static bool ODProgress = false; // on death in progress - ODProgress
    
    if (ODProgress) {
        return;
    }
    
    ODProgress = true;
    
    Player& curr_player = this->getPlayer();
    unsigned int new_exp = curr_player.getExp() + this->getExp();
    curr_player.setExp(new_exp);
    unsigned int new_gold = curr_player.getGold() + this->getExp() * 2;
    curr_player.setGold(new_gold);
    
    std::cout << "💥 Yard dragon is dead 💥" << std::endl;
    
    ODProgress = false;
}

void YardDragon::FireAttack(GameField& field, Player& player)
{
    UpdateFireVisual(field, player);
    fire_visuals.clear();

    for (int ax = -attack_range + 1; ax < attack_range; ax++)
    {
        for (int ay = -attack_range + 1; ay < attack_range; ay++)
        {
            if (ax == 0 && ay == 0) continue;
            // pass if its dragon

            int attackX = this->getX_pos() + ax;
            int attackY = this->getY_pos() + ay;

            int playerX = player.getX_pos();
            int playerY = player.getY_pos();

            if ((fire_count == 0 || fire_count == 6) && ((abs(ax) == 1 || ax == 0) && (abs(ay) == 1 || ay == 0)))
            {
                if (field.getSymbol(attackX, attackY) != '#' && field.getSymbol(attackX, attackY) != 'E' && field.getSymbol(attackX, attackY) != 'T' && field.getSymbol(attackX, attackY) != '@')
                {
                    fire_visuals.push_back({attackX, attackY});
                    field.setSymbol(attackX, attackY, '~');
                }
    
                if (playerX == attackX && playerY == attackY)
                {
                    player.takeDamage(this->getDamage());
                }
            }
            else if ((fire_count == 1 || fire_count == 5) && ((abs(ax) <= 1 && abs(ay) == 2) || (abs(ax) == 2 && abs(ay) <= 2)))
            {
                if (field.getSymbol(attackX, attackY) != '#' && field.getSymbol(attackX, attackY) != 'E' && field.getSymbol(attackX, attackY) != 'T' && field.getSymbol(attackX, attackY) != '@')
                {
                    fire_visuals.push_back({attackX, attackY});
                    field.setSymbol(attackX, attackY, '~');
                }
    
                if (playerX == attackX && playerY == attackY)
                {
                    player.takeDamage(this->getDamage());
                }
            }
            else if ((fire_count == 2 || fire_count == 4) && ((abs(ax) <= 2 && abs(ay) == 3) || (abs(ax) == 3 && abs(ay) <= 3)))
            {
                if (field.getSymbol(attackX, attackY) != '#' && field.getSymbol(attackX, attackY) != 'E' && field.getSymbol(attackX, attackY) != 'T' && field.getSymbol(attackX, attackY) != '@')
                {
                    fire_visuals.push_back({attackX, attackY});
                    field.setSymbol(attackX, attackY, '~');
                }
    
                if (playerX == attackX && playerY == attackY)
                {
                    player.takeDamage(this->getDamage());
                }
            }
            else if (fire_count == 3 && ((abs(ax) <= 3 && abs(ay) == 4) || (abs(ax) == 4 && abs(ay) <= 4)))
            {
                if (field.getSymbol(attackX, attackY) != '#' && field.getSymbol(attackX, attackY) != 'E' && field.getSymbol(attackX, attackY) != 'T' && field.getSymbol(attackX, attackY) != '@')
                {
                    fire_visuals.push_back({attackX, attackY});
                    field.setSymbol(attackX, attackY, '~');
                }
    
                if (playerX == attackX && playerY == attackY)
                {
                    player.takeDamage(this->getDamage());
                }
            }
        }
    }
}

void YardDragon::UpdateFireVisual(GameField& field, Player& player)
{
    for (auto i = fire_visuals.begin(); i != fire_visuals.end();) // i - iterator, so use ->, no .
    {
        if (field.getSymbol(i->x, i->y) == '~')
        {
            bool flag = false;
            if (player.getX_pos() == i->x && player.getY_pos() == i->y)
            {
                field.setSymbol(i->x, i->y, '@');
                flag = true;
            }
            // field.draw(); // draw the field
            if (!flag)
            {
                field.setSymbol(i->x, i->y, ' ');
            }
        }
        i = fire_visuals.erase(i);
    }
}

unsigned int YardDragon::getAttackRange() const
{
    return attack_range;
}

void YardDragon::setAttackRange(int new_range)
{
    attack_range = new_range;
}

int YardDragon::getFireCount() const
{
    return fire_count;
}

void YardDragon::setFireCount(int new_value)
{
    fire_count = new_value;
}

bool YardDragon::getCanMove() const
{
    return can_move;
}

void YardDragon::setCanMove(bool new_value)
{
    can_move = new_value;
}

void YardDragon::move(Player& player, GameField& field)
{
    int player_x = player.getX_pos();
    int player_y = player.getY_pos();

    int dist_x = player_x - this->getX_pos();
    int dist_y = player_y - this->getY_pos();

    int new_x = this->getX_pos();
    int new_y = this->getY_pos();

    if (can_move)
    {
        if (!field.checkCollision(this->getX_pos(), this->getY_pos()) && dist_x <= 8 && dist_y <= 8)
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
                field.setSymbol(this->getX_pos(), this->getY_pos(), 'Y');
            }
        }
    }
}