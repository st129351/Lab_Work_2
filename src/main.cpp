//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include <gtest/gtest.h>
#include <cstdio>
#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "GameField.h"
#include "Player.h"
#include "Enemy.h"
#include "Slime.h"
#include "Fighter.h"
#include "Amulet.h"


void enableRawMode() 
{
	struct termios raw; // struct for storage terminal settings
	tcgetattr(STDIN_FILENO, &raw); // get current terminal settings

	raw.c_lflag &= ~(ICANON | ECHO); // disable canon mode (now without 'enter')
	// disable echo (without repeat letters in the console)

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // apply settings
	// TCSAFLUSH - apply settings after all input was read
}

void disableRawMode()
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &raw);
	// return settings as it was
	raw.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
	Player player;
	GameField field(player);
	field.slimeSpawn(28, 2); // spawn slime
	int input;

	enableRawMode();
	// immidiately read the input letters

	std::cout << "hi, dear player" << std::endl;
	std::cout << "use WASD to move" << std::endl;
	std::cout << "use J to attack" << std::endl;
	std::cout << "use Q to quit" << std::endl;

	while (true)
	{
		std::cout << "\033[2J\033[1;1H"; // clear the console

		std::cout << "your HP:" << player.getHealth() << std::endl;


		for (auto& enemy : field.getEnemies())
		{
			std::cout << enemy->getName() << " HP:" << enemy->getHealth() <<std::endl;
		}

		field.draw(); // draw the field
		field.moveEnemies();
		field.combat();
		player.UpdateAttackVisual(field, field.getEnemies());
		usleep(100); // for smooth movement

		if (!player.isAlive())
		{
			break;
		}

		input = getchar(); // get the input letter from keyboard
		if (input == 'q')
		{
			disableRawMode(); // return settings as it was
			break;
		}
		// for walking use only WASD
		if (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'j')
		{
			field.Movement(input); // processing the input value
		}
	}
	return 0;
}