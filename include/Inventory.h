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
    const unsigned int max_slots = 20;
    unsigned int size;
    Player& player;

    std::vector<std::shared_ptr<Amulet>> amulets; // ptr for strorage diffenert amulets (polymorphism with base class)
    // smart ptr to not use 'delete' operator

    // add vector for unique items from different enemy
    // and show for it
public:
    Inventory(Player& p);

    std::string show();

    // realisation of template func here
    template<typename T>
    void add(std::shared_ptr<T> item);

    template<typename T>
    void remove(std::shared_ptr<T> item);

    template<typename T>
    void put_on(size_t index);

    template<typename T>
    void take_off(size_t index);

};

#endif