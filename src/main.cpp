//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include "Game.h"

int main()
{
	Player p;

	Game game(p);
	game.Level_1();
	if (!p.isAlive()) return 0;
	game.startVillage();
	if (!p.isAlive()) return 0;
	game.Level_2();
	if (!p.isAlive()) return 0;
	game.Level_3();
	
	return 0;
}