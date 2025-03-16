#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <memory> // shared_ptr
// because one enemy_type in one room
#include <vector>

#include "Enemy.h"

class Room
{
private:
    char field[35][20];
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Enemy>> enemies;
public:
    Room(std::string name, std::string description);
    void initializeRoom();
    void draw();

    
};

#endif
