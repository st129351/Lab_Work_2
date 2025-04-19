#include "NPC.h"

NPC::NPC(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->dialogue_complete = false;
}

std::string NPC::getName() const
{
    return name;
}

std::string NPC::getDescription() const
{
    return description;
}

bool NPC::getDialogueComplete() const
{
    return dialogue_complete;
}

void NPC::setName(std::string new_name)
{  
    name = new_name;
}

void NPC::setDescription(std::string new_description)
{  
    description = new_description;
}

void NPC::setDialogueComplete(bool new_value)
{
    dialogue_complete = new_value;
}

int NPC::getX_pos() const
{
    return x_pos;
}

int NPC::getY_pos() const
{
    return y_pos;
}

void NPC::setX_pos(int new_pos)
{
    x_pos = new_pos;
}

void NPC::setY_pos(int new_pos)
{
    y_pos = new_pos;
}