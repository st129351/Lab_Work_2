#ifndef ADASH_H
#define ADASH_H

#include "Amulet.h"
#include <vector>

class GameField;
class Player;

class ADash : public Amulet
{
private:
    GameField& field;
    struct DashVisual
    {
        int x, y;
    };
    std::vector<DashVisual> dash_visual;
public:
    ADash(GameField& f);
    ~ADash() override;
    void UpdateDashVisual();
    void use(Player& player) override;
};

#endif