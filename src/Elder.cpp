#include "Elder.h"

Elder::Elder() : NPC("Elder", "The Elder of ancient village.") 
{
    mission1 = true;
    mission2 = false;
    mission3 = false; // control of realization missions
}

Elder::~Elder() {}

void Elder::speak()
{
    if (mission1)
    {
        std::cout << "(use enter to continue the dialogue)" << std::endl;
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Can.. can you help me?" << std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "As you might have noticed, this is ancient village..." << std::endl;
        std::cout << "But earlier... " << std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "There was a lot of life here." << std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "The reason is - magician, who named himself 'Yard Dragon', really strange name..";
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "After the death of his dragon, he's gone berserk and studied the magic of ancients." << std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Because of him my village was destroyed and now..." << std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "And now there are terrible people and monsters roaming around her, who have joined the all-destructive policy of the Yard Dragon." <<std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "You must clear the surroundings of the village of him and his henchmen." << std::endl;
        getchar();
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Can you handle it..?" << std::endl;
        setDialogueComplete(true);
        mission1 = false;
    }
    else if (mission2)
    {
        std::cout << "You are so strog and brave knight. But now..." << std::endl;
        std::cout << "You'll appear before Yard Dragon. " << std::endl;
        std::cout << "Are you ready?" <<std::endl;
        setDialogueComplete(true);
        mission2 = false;
    }
    else if (mission3)
    {
        std::cout << "Thank you! Thanks to you my village going to be the best place on earth again soon." << std::endl;
        std::cout << "YOU WIN" << std::endl;
        setDialogueComplete(true);
        mission3 = false;
    }
    else
    {
        std::cout << "Ok, you're really strong!" << std::endl;
        setDialogueComplete(true);
        mission3 = true;
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