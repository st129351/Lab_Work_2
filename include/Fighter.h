#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <iostream>
#include <vector>

class Fighter
{
private:
    unsigned int health;
    unsigned int damage;
    std::string name;
public:
    Fighter(const std::string& name, unsigned int health, unsigned int damage);
    virtual ~Fighter() {} // virtual default destructor
    virtual void onDeath() = 0; // pure virtual function (function hasn't realisation in base class)
    // function that will be realised in derived classes

    void attack(Fighter &target);
    void takeDamage(unsigned int damage);
    bool isAlive() const;

    std::string getName() const;
    unsigned int getDamage() const;
    unsigned int getHealth() const;

    void setHealth(unsigned int& new_health);
    void setDamage(unsigned int& new_damage);
    void setName(const std::string& new_name);

};

#endif

