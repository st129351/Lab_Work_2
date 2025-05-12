//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include "Game.h"
#include "string"

int main()
{
	std::string name;
	std::cout << "Enter the name of your hero: ";
    // std::cin.ignore(); // clear buffer, if \n
    std::getline(std::cin, name);
	Player p(name);

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