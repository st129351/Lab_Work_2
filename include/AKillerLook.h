#ifndef AKILLERLOOK_H
#define AKILLERLOOK_H

#include "Amulet.h"
#include <memory>

class Player;
class Enemy;
class GameField;

class AKillerLook : public Amulet
{
private:
    const unsigned int fear_percentage;
    std::string killer_look_description;
    std::vector<std::shared_ptr<Enemy>> enemies;
    // vector for all enemies, who will be affected by the amulet
public:
    AKillerLook(std::vector<std::shared_ptr<Enemy>> e);
    ~AKillerLook() override;

    void use(Player& p) override;

    unsigned int getFearPercentage() const;
    std::string getKillerLookDescription() const;
    void setKillerLookDescription(std::string new_killer_look_description);
};

#endif