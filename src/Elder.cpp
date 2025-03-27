#include "Elder.h"

Elder::Elder() : NPC("Elder", "The Elder of ancient village.") 
{
    mission1 = true;
    mission2 = true;
    mission3 = true; // control of realization missions
}

Elder::~Elder() {}

void Elder::speak()
{
    std::cout << "Hello!" << std::endl;

    if (mission1)
    {
        std::cout << "Can.. can you help me?" << std::endl;
        std::cout << "As you might have noticed, this is ancient village..." << std::endl;
        std::cout << "But earlier... " << std::endl;
        std::cout << "There was a lot of life here." << std::endl;
        std::cout << "The reason is - magician, who named himself 'Yard Dragon', really strange name..";
        std::cout << "After the death of his dragon, he's gone berserk and studied the magic of ancients." << std::endl;
        std::cout << "Because of him my village was destroyed and now..." << std::endl;
        std::cout << "And now there are terrible people and monsters roaming around her, who have joined the all-destructive policy of the Yard Dragon." <<std::endl;
        std::cout << "You must clear the surroundings of the village of him and his henchmen." << std::endl;
        std::cout << "Can you handle it..?" << std::endl;
        mission1 = false;
    }
    if (mission2)
    {
        std::cout << "You are so strog and brave knight. But now..." << std::endl;
        std::cout << "You'll appear before Yard Dragon. " << std::endl;
        std::cout << "Are you ready?" <<std::endl;
        mission2 = false;
    }
    if (mission3)
    {
        std::cout << "Thank you! Thanks to you my village going to be the best place on earth again soon." << std::endl;
    }
}

bool Elder::getMission1() const
{
    return mission1;
}

bool Elder::getMission2() const
{
    return mission2;
}

bool Elder::getMission3() const
{
    return mission3;
}

void Elder::setMission1(bool value) 
{
    mission1 = value;
}

void Elder::setMission2(bool value) 
{
    mission2 = value;
}

void Elder::setMission3(bool value) 
{
    mission3 = value;
}