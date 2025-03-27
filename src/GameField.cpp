#include "GameField.h"
#include "Player.h"
#include "Slime.h"
#include "Enemy.h"

GameField::GameField(Player& p) : player(p)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i==0 || i == 14 || j == 0 || j == 29)
            {
                field[j][i] = '#';
            }
            else
            {
                field[j][i] = ' ';
            }
        }
    }
    playerSpawn(player.getX_pos(), player.getY_pos());
}

GameField::~GameField() {}

void GameField::draw() const
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            std::cout << field[j][i];
        }
        std::cout << std::endl;
    }
}

char GameField::getSymbol(int x, int y) const
{
    if (x >= 0 && x < 30 && y >= 0 && y < 15)
    {
        return field[x][y];
    }
    return ' ';
}

void GameField::setSymbol(int x, int y, char new_symbol)
{
    if (x >= 0 && x < 30 && y >= 0 && y < 15)
    {
        field[x][y] = new_symbol;
    }
}

void GameField::playerSpawn(int x, int y)
{
    setSymbol(x, y, '@');
}

void GameField::Movement(char where)
{
    int new_x = player.getX_pos();
    int new_y = player.getY_pos();

    switch (tolower(where))
    {
        case 'w': new_y--; break;
        case 's': new_y++; break;
        case 'a': new_x--; break;
        case 'd': new_x++; break;
        case 'j': player.attackArea(*this, enemies);
        return;
    }
    // add collision on walls and enemies
    if (getSymbol(new_x, new_y) != '#' && getSymbol(new_x, new_y) != '~')
    {
        setSymbol(player.getX_pos(), player.getY_pos(), ' ');
        
        player.setX_pos(new_x);
        player.setY_pos(new_y);

        setSymbol(player.getX_pos(), player.getY_pos(), '@');
    }
}

void GameField::slimeSpawn(int x, int y)
{
    auto slime = std::make_shared<Slime>("Slime", 25, 5, 10, 3);
    std::shared_ptr<Enemy> enemy = slime;
    enemy->setX_pos(x);
    enemy->setY_pos(y);
    enemies.push_back(enemy);
    setSymbol(x, y, '~');
}

bool GameField::checkCollision(int x, int y)
{
    int a = player.getX_pos() - x;
    int b = player.getY_pos() - y;
    if (abs(a) <= 1 && abs(b) <= 1)
    {
        return true;
    }
    return false;
}

void GameField::combat()
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (checkCollision(enemies[i]->getX_pos(), enemies[i]->getY_pos()))
        {
            enemies[i]->attack(player);
            if (auto slime = dynamic_cast<Slime*>(enemies[i].get())) // get() - take pointer to the enemy
            // dinamic_cast - transform it to ptr to the Slime
            // if enemy isnt Slime, --> auto slime = nullptr (thanks to auto)
            {
                slime->applyPoison(player);
            }
            
            if (!(enemies[i]->isAlive()))
            {
                setSymbol(enemies[i]->getX_pos(), enemies[i]->getY_pos(), ' ');
                enemies.erase(enemies.begin() + i);
                break;
            }
        }
    }
}

std::vector<std::shared_ptr<Enemy>>& GameField::getEnemies()
{
    return enemies;
}

void GameField::moveEnemies()
{
    for (auto& enemy : enemies)
    {
        enemy->move(player, *this);
    }
}

