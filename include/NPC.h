#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>
#include <vector>

class NPC
{
private:
    std::string name;
    std::string description;
    int x_pos;
    int y_pos;
    bool dialogue_complete;
public:
    NPC(std::string name, std::string description);
    virtual ~NPC() = default;

    virtual void speak() = 0;

    std::string getName() const;
    std::string getDescription() const;
    bool getDialogueComplete() const;

    void setName(std::string new_name);
    void setDescription(std::string new_description);
    void setDialogueComplete(bool new_value);

    int getX_pos() const;
    int getY_pos() const;

    void setX_pos(int new_pos);
    void setY_pos(int new_pos);
};

#endif