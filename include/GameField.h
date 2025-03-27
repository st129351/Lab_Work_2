#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include <memory>

class Player;
class Enemy;
// forward declaration

class GameField
{
private:
    char field[30][15];
    Player& player;
    std::vector<std::shared_ptr<Enemy>> enemies;
public:
    GameField(Player& p);
    ~GameField();

    void draw() const;
    // for drawing the field in the console 
    // not change the field --> const

    char getSymbol(int x, int y) const;
    void setSymbol(int x, int y, char symbol);

    void playerSpawn(int x, int y);
    // void enemySpawn(int x, int y);
    void slimeSpawn(int x, int y);
    bool checkCollision(int x, int y);
    void combat();

    void Movement(char where);
    // for movement of the player

    std::vector<std::shared_ptr<Enemy>>& getEnemies();

    void moveEnemies();

};


#endif