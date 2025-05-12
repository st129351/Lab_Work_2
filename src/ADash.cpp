//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "ADash.h"
#include "GameField.h"
#include "Player.h"

ADash::ADash() : Amulet(25, false, "dash", "incredible speed, press 'k'", 8), field(nullptr) {}

ADash::ADash(GameField& f) : Amulet(25, false, "dash", "incredible speed, press 'k'", 8), field(&f) {}

ADash::~ADash() {};

void ADash::UpdateDashVisual()
{
    for (auto i = dash_visual.begin(); i != dash_visual.end();)
    {
        if (field->getSymbol(i->x, i->y) == '|' || field->getSymbol(i->x, i->y) == '-')
        {
            field->setSymbol(i->x, i->y, ' ');
        }
        i = dash_visual.erase(i);
    }
}

void ADash::use(Player& player)
{

    char symb = field->getInputSymb();
    int new_x = player.getX_pos();
    int new_y = player.getY_pos();

    int count = 0;
    if (tolower(symb) == 'w')
    {
        new_y--;
        count += 1;
        while (count <= 2 && field->getSymbol(new_x, new_y) != '#' && field->getSymbol(new_x, new_y) != 's' && field->getSymbol(new_x, new_y) != 'b' && field->getSymbol(new_x, new_y) != 'Y' && field->getSymbol(new_x, new_y) != 'E' && field->getSymbol(new_x, new_y) != 'T')
        {
            if (count == 1 || count == 2)
            {
                field->setSymbol(player.getX_pos(), player.getY_pos(), '|');
                dash_visual.push_back({player.getX_pos(), player.getY_pos()});
                player.setX_pos(new_x);
                player.setY_pos(new_y);
                field->setSymbol(player.getX_pos(), player.getY_pos(), '@');
            }
            new_y--;
            count += 1;
        }
    }
    else if (tolower(symb) == 'a')
    {
        new_x--;
        count += 1;
        while (count <= 2 && field->getSymbol(new_x, new_y) != '#' && field->getSymbol(new_x, new_y) != 's' && field->getSymbol(new_x, new_y) != 'b' && field->getSymbol(new_x, new_y) != 'Y' && field->getSymbol(new_x, new_y) != 'E' && field->getSymbol(new_x, new_y) != 'T')
        {
            if (count == 1 || count == 2)
            {
                field->setSymbol(player.getX_pos(), player.getY_pos(), '-');
                dash_visual.push_back({player.getX_pos(), player.getY_pos()});
                player.setX_pos(new_x);
                player.setY_pos(new_y);
                field->setSymbol(player.getX_pos(), player.getY_pos(), '@');
            }
            new_x--;
            count += 1;
        }
    }
    else if (tolower(symb) == 's')
    {
        new_y++;
        count += 1;
        while (count <= 2 && field->getSymbol(new_x, new_y) != '#' && field->getSymbol(new_x, new_y) != 's' && field->getSymbol(new_x, new_y) != 'b' && field->getSymbol(new_x, new_y) != 'Y' && field->getSymbol(new_x, new_y) != 'E' && field->getSymbol(new_x, new_y) != 'T')
        {
            if (count == 1 || count == 2)
            {
                field->setSymbol(player.getX_pos(), player.getY_pos(), '|');
                dash_visual.push_back({player.getX_pos(), player.getY_pos()});
                player.setX_pos(new_x);
                player.setY_pos(new_y);
                field->setSymbol(player.getX_pos(), player.getY_pos(), '@');
            }
            new_y++;
            count += 1;
        }
    }
    else if (tolower(symb) == 'd')
    {
        new_x++;
        count += 1;
        while (count <= 2 && field->getSymbol(new_x, new_y) != '#' && field->getSymbol(new_x, new_y) != 's' && field->getSymbol(new_x, new_y) != 'b' && field->getSymbol(new_x, new_y) != 'Y' && field->getSymbol(new_x, new_y) != 'E' && field->getSymbol(new_x, new_y) != 'T')
        {
            if (count == 1 || count == 2)
            {
                field->setSymbol(player.getX_pos(), player.getY_pos(), '-');
                dash_visual.push_back({player.getX_pos(), player.getY_pos()});
                player.setX_pos(new_x);
                player.setY_pos(new_y);
                field->setSymbol(player.getX_pos(), player.getY_pos(), '@');
            }
            new_x++;
            count += 1;
        }
    }
}