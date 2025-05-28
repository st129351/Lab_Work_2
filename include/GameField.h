#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include <memory>
# include <cctype> // to use fast checking for a number (isdigit)

class Player;
class Enemy;
class YardDragon;
class NPC;
class Elder;
class Trader;
// forward declaration

class GameField
{
private:
    char field[30][15];
    Player& player;
    std::shared_ptr<YardDragon>& dragon;
    std::shared_ptr<Elder> elder;
    std::shared_ptr<Trader> trader;
    std::vector<std::shared_ptr<NPC>> npc_characters;
    bool p_was_seen_d;
    char input_symb;
protected:
    std::vector<std::shared_ptr<Enemy>> enemies;
public:
    GameField(Player& p, std::shared_ptr<YardDragon>& d);
    ~GameField();

    void draw() const;
    // for drawing the field in the console 
    // not change the field --> const

    char getSymbol(int x, int y) const;
    void setSymbol(int x, int y, char symbol);
    bool getPWasSeenD() const;
    void setPWasSeenD(bool new_value);
    char getInputSymb() const;
    void setInputSymb(char new_symb);
    std::shared_ptr<Elder> getElder();

    void playerSpawn(int x, int y);
    // void enemySpawn(int x, int y);
    void yardDragonSpawn(int x, int y);
    void elderSpawn(int x, int y);
    void traderSpawn(int x, int y);
    YardDragon& getDragon();
    void slimeSpawn(int x, int y);
    void banditSpawn(int x, int y);
    bool checkCollision(int x, int y);
    bool checkDragonRange(int x, int y);
    void combat();

    void Buy(char symb);
    void Movement(char where);
    void Interaction(char what);
    // for movement of the player

    std::vector<std::shared_ptr<Enemy>>& getEnemies();
    std::vector<std::shared_ptr<NPC>>& getNPC();

    void moveEnemies();

};


#endif