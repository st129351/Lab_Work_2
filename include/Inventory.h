#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory> // for smart ptr
#include <string>
// Forward declarations
class Player;
class Amulet;

class Inventory
{
private:
    const unsigned int max_slots = 25;
    unsigned int size;
    Player& player;

    std::vector<std::shared_ptr<Amulet>> amulets; // ptr for strorage diffenert amulets (polymorphism with base class)
    // smart ptr to not use 'delete' operator

    // add vector for unique items from different enemy
    // and show for it
public:
    Inventory(Player& p);

    std::string show();

    void add(std::shared_ptr<Amulet> item);
};

#endif