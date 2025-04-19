#include "Inventory.h"
#include "Player.h"
#include "Amulet.h"
#include <sstream>

Inventory::Inventory(Player& p): size(0), player(p) {}

std::string Inventory::show()
{
    std::stringstream ss;
    ss << "Size: " << size << "/" << max_slots << std::endl;
    ss << "--------------------------------" << std::endl;
    for (const auto& amulet : amulets)
    {
        ss << amulet->getName() << std::endl;
        ss << "Description: " << amulet->getDescription() << std::endl;
        // ss << "Cost: " << player.getGold() << "/" << amulet->getCost() << std::endl;
        if (amulet->getUsage() == true)
        {
            ss << "The '" << amulet->getName() << "' is on" << std::endl;
        }
        else
        {
            ss << "The '" << amulet->getName() << "' is off" << std::endl;
        }
        ss << "--------------------------------" << std::endl;
    }
    return ss.str();
}

void Inventory::add(std::shared_ptr<Amulet> item)
{
    if (size + item->getSlots() <= max_slots)
    {
        amulets.push_back(item);
        size = size + item->getSlots();
        std::cout << player.getName() << ", your '" << item->getName() << "' is used!" << std::endl;
        std::cout << "Successful, thank you!";
    }
    else
    {
        std::cout << "not enough slots" << std::endl;
    }

    if (size == max_slots)
    {
        std::cout << "Inventory is full" << std::endl;
    }
}
