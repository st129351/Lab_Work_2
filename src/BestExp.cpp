//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "BestExp.h"
#include "Player.h"

BestExp::BestExp(Player& p) : Amulet(15, false, "bestexp", "increases the experience at every step", 1)
{
    best_exp_description = "increases the experience at every step";
    add_exp = 1;
}

BestExp::~BestExp() {}

void BestExp::use(Player& p)
{
    p.setExp(p.getExp() + add_exp);
}

unsigned int BestExp::getAddExp() const
{
    return add_exp;
}

void BestExp::setAddExp(unsigned int new_exp)
{
    add_exp = new_exp;
}