//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "GameField.h"
#include "Player.h"
#include "Slime.h"
#include "Enemy.h"
#include "Bandit.h"
#include "YardDragon.h"
#include "Elder.h"
#include "Trader.h"

GameField::GameField(Player& p, std::shared_ptr<YardDragon>& d) : player(p), dragon(d)
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
    p_was_seen_d = false;
    input_symb = 'w';
    elder = nullptr;
    trader = nullptr;
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

bool GameField::getPWasSeenD() const
{
    return p_was_seen_d;
}

void GameField::setPWasSeenD(bool new_value)
{
    p_was_seen_d = new_value;
}

char GameField::getInputSymb() const
{
    return input_symb;
}

void GameField::setInputSymb(char new_symb)
{
    input_symb = new_symb;
}

std::shared_ptr<Elder> GameField::getElder()
{
    return elder;
}

void GameField::playerSpawn(int x, int y)
{
    setSymbol(x, y, '@');
}

void GameField::Buy(char symb)
{
    player.Buy(npc_characters, symb, *this);
}
void GameField::Movement(char where)
{
    int new_x = player.getX_pos();
    int new_y = player.getY_pos();

    switch (where)
    {
        case 'w': new_y--; break;
        case 's': new_y++; break;
        case 'a': new_x--; break;
        case 'd': new_x++; break;
        case 'j': player.attackArea(*this, enemies); break;
        return;
    }

    // add collision on walls and enemies
    if (getSymbol(new_x, new_y) != '#' && getSymbol(new_x, new_y) != 's' && getSymbol(new_x, new_y) != 'b' && getSymbol(new_x, new_y) != 'Y' && getSymbol(new_x, new_y) != 'E' && getSymbol(new_x, new_y) != 'T')
    {
        setSymbol(player.getX_pos(), player.getY_pos(), ' ');
        
        player.setX_pos(new_x);
        player.setY_pos(new_y);

        setSymbol(player.getX_pos(), player.getY_pos(), '@');
    }
}

void GameField::Interaction(char what)
{
    // Проверка, запускаемся ли мы в среде тестирования
    bool in_test_environment = (getenv("RUNNING_TESTS") != nullptr);
    
    switch (what)
    {
        case 'e':
            std::cout << "\033[2J\033[1;1H"; 
            player.NPCSpeak(npc_characters);
            std::cout << "Press any key to continue..." << std::endl;
            if (!in_test_environment) getchar();
            std::cout << "\033[2J\033[1;1H";
            break;
        case 'i': 
            std::cout << "\033[2J\033[1;1H";
            std::cout << player.showInventory() << std::endl; break;
            std::cout << "Press any key to continue..." << std::endl;
            if (!in_test_environment) getchar();
            break;
        return;
    }
}
// spawn enemies
void GameField::yardDragonSpawn(int x, int y)
{
    std::shared_ptr<Enemy> enemy = dragon;
    enemy->setX_pos(x);
    enemy->setY_pos(y);
    enemies.push_back(enemy);
    setSymbol(x, y, 'Y');
}

void GameField::slimeSpawn(int x, int y)
{
    auto slime = std::make_shared<Slime>("Slime", 25, 5, 10, 10, &player, 3); // player not a ptr (a ref), 
    // but we get a address of the reference, Player& player: - player - ref
    std::shared_ptr<Enemy> enemy = slime;
    enemy->setX_pos(x);
    enemy->setY_pos(y);
    enemies.push_back(enemy);
    setSymbol(x, y, 's');
}

void GameField::banditSpawn(int x, int y)
{
    auto bandit = std::make_shared<Bandit>("Bandit", 15, 5, 30, 3, &player);
    std::shared_ptr<Enemy> enemy = bandit;
    enemy->setX_pos(x);
    enemy->setY_pos(y);
    enemies.push_back(enemy);
    setSymbol(x, y, 'b');
}

void GameField::elderSpawn(int x, int y)
{
    elder = std::make_shared<Elder> (); // MUST SPAWN
    std::shared_ptr<NPC> npc = elder;
    npc->setX_pos(x);
    npc->setY_pos(y);
    npc_characters.push_back(npc);
    setSymbol(x, y, 'E');
}

void GameField::traderSpawn(int x, int y)
{
    trader = std::make_shared<Trader> (player, *this);
    std::shared_ptr<NPC> npc = trader;
    npc->setX_pos(x);
    npc->setY_pos(y);
    npc_characters.push_back(npc);
    setSymbol(x, y, 'T');
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

bool GameField::checkDragonRange(int x, int y)
{
    int a = player.getX_pos() - x;
    int b = player.getY_pos() - y;
    if (abs(a) <= dragon->getAttackRange() && abs(b) <= dragon->getAttackRange())
    {
        return true;
    }
    return false;
}

void GameField::combat()
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (auto dragon = dynamic_cast<YardDragon*> (enemies[i].get()))
        {
            if (checkDragonRange(dragon->getX_pos(), dragon->getY_pos()))
            {
                p_was_seen_d = true;
                dragon->setCanMove(false); // start attack

                dragon->FireAttack(*this, player);

                if (!(dragon->isAlive()))
                {
                    setSymbol(dragon->getX_pos(), dragon->getY_pos(), ' ');
                    // dragon->onDeath();
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            }
            else if (!checkDragonRange(dragon->getX_pos(), dragon->getY_pos()) && p_was_seen_d) // if player was seen by dragon
            {
                dragon->setCanMove(false); // start attack

                dragon->FireAttack(*this, player);

                if (!(dragon->isAlive()))
                {
                    setSymbol(dragon->getX_pos(), dragon->getY_pos(), ' ');
                    // dragon->onDeath();
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            }
            else if (!checkDragonRange(dragon->getX_pos(), dragon->getY_pos()) && !p_was_seen_d)
            {
                dragon->UpdateFireVisual(*this, player);
                if (!(dragon->isAlive()))
                {
                    setSymbol(dragon->getX_pos(), dragon->getY_pos(), ' ');
                    // dragon->onDeath();
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            }
            
        }
        // and realisation for another enemy type
        else
        {
            if (checkCollision(enemies[i]->getX_pos(), enemies[i]->getY_pos()))
            {
                enemies[i]->attack(player); // base attack
    
                if (auto slime = dynamic_cast<Slime*>(enemies[i].get())) // get() - take pointer to the enemy
                // dinamic_cast - transform it to ptr to the Slime
                // if enemy isnt Slime, --> auto slime = nullptr (thanks to auto)
                {
                    slime->applyPoison(player);
                }
                if (!(enemies[i]->isAlive()))
                {
                    setSymbol(enemies[i]->getX_pos(), enemies[i]->getY_pos(), ' ');
                    // enemies[i]->onDeath(); 
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            }
        }
    }

}

std::vector<std::shared_ptr<Enemy>>& GameField::getEnemies()
{
    return enemies;
}

std::vector<std::shared_ptr<NPC>>& GameField::getNPC()
{
    return npc_characters;
}

void GameField::moveEnemies()
{
    for (auto& enemy : enemies)
    {
        enemy->move(player, *this);
    }
}

YardDragon& GameField::getDragon()
{
    return *dragon;
}
