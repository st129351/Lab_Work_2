#ifndef ELDER_H
#define ELDER_H

#include "NPC.h"

class Elder : public NPC 
{
private:
    bool mission1;
    bool mission2;
    bool mission3;
public:
    Elder();
    ~Elder() override;

    void speak() override;
    
    bool getMission1() const;
    bool getMission2() const;
    bool getMission3() const;

    void setMission1(bool value);
    void setMission2(bool value);
    void setMission3(bool value);
};

#endif