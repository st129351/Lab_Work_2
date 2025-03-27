#include "Inventory.h"
#include "Player.h"
#include "Amulet.h"
#include <sstream>

Inventory::Inventory(Player& p): size(0), player(p) {}

std::string Inventory::show()
{
    std::stringstream ss;
    ss << "Inventory size: " << size << "/" << max_slots << std::endl;
    for (const auto& amulet : amulets)
    {
        ss << amulet->getName() << std::endl;
        ss << "Description: " << amulet->getDescription() << std::endl;
        // ss << "Cost: " << player.getGold() << "/" << amulet->getCost() << std::endl;
        if (amulet->getUsage() == true)
        {
            ss << "The " << amulet->getName() << " is on" << std::endl;
        }
        else
        {
            ss << "The " << amulet->getName() << " is off" << std::endl;
        }
        ss << "--------------------------------" << std::endl;
    }
    return ss.str();
}

void Inventory::add(std::shared_ptr<Amulet> item)
{
    if (size + item->getSlots() < max_slots)
    {
        amulets.push_back(item);
        size = size + item->getSlots();
    }

    if (size == max_slots)
    {
        std::cout << "Inventory is full" << std::endl;
    }
}

void Inventory::remove(std::shared_ptr<Amulet> item)
{
    for (size_t i = 0; i < amulets.size(); i++) // vector.size() usually return "size_t" type
    {
        if (amulets[i] == item)
        {
            amulets.erase(amulets.begin() + i);
            size--;
        }
    }
}

void Inventory::put_on(size_t index)
{
    if (amulets[index]->getUsage() == true)
    {
        std::cout << "Amulet is already use" << std::endl;
        return;
    }
    else
    {
        amulets[index]->setUsage(true);
        amulets[index]->use(player);
        std::cout << "Amulet is used" << std::endl;
    }
}

void Inventory::take_off(size_t index)
{
    if (amulets[index]->getUsage() == false)
    {
        std::cout << "Amulet already off" << std::endl;
        return;
    }
    else
    {
        amulets[index]->setUsage(false);
        amulets[index]->dont_use(player);
        std::cout << "Amulet is off" << std::endl;
    }
}