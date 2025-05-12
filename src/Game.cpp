//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2
#include "Game.h"
#include "Enemy.h"
#include "Slime.h"
#include "Fighter.h"
#include "Amulet.h"
#include "YardDragon.h"
#include "APerseverance.h"
#include "BestExp.h"
#include "AHeal.h"
#include "ADash.h"
#include "NPC.h"
#include "Elder.h"

Game::Game(Player& p) : player(p), field(player, dragon)
{
    dragon = std::make_shared<YardDragon>("Yard Dragon", 200, 30, 45, 100, &player, 5);
    flag = 0;
	completeLevel = false;
	endGame = false;
}

void Game::enableRawMode()
{
    struct termios raw; // struct for storage terminal settings
	tcgetattr(STDIN_FILENO, &raw); // get current terminal settings

	raw.c_lflag &= ~(ICANON | ECHO); // disable canon mode (now without 'enter')
	// disable echo (without repeat letters in the console)

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // apply settings
	// TCSAFLUSH - apply settings after all input was read
}

void Game::disableRawMode()
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &raw);
	// return settings as it was
	raw.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void Game::start_game()
{
    enableRawMode();
    while (true)
	{
		if (field.getEnemies().empty() && !completeLevel)
		{
			size_t count = 0;
			for (std::shared_ptr<NPC> npc : field.getNPC())
			{
				if (npc->getDialogueComplete())
				{
					count += 1;
				}
			}
			if (count == field.getNPC().size())
			{
				completeLevel = true;
				break;
			}
		}
		if (flag < 1)
		{
			std::cout << "\033[2J\033[1;1H"; // clear the console
			std::cout << R"(
 ▄▄▄    ████╗███████╗███╗   ███╗ █████╗     ▄▄▄ 
▐   ▐    ██╔╝╚══███╔╝████╗ ████║██╔══██╗   ▐   ▐
 ▐   ▀▀▄▀██║   ███╔╝ ██╔████╔██║███████║▀▄▀▀  ▐
◇   ██   ██║  ███╔╝  ██║╚██╔╝██║██╔══██║   ██  ◇
   ▐  ▐ ████╗███████╗██║ ╚═╝ ██║██║  ██║  ▐  ▐
  ▐    ▐╚═══╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝ ▐    ▐
  ◇     ▐       ▐        ▐       ▐       ▐     ◇
       ◇  ◇      ▐      ▐       ▐       ◇  ◇
                 ◇       ◇      ◇)" << std::endl;
			std::cout << "hi, dear " << player.getName() << "!" << std::endl;
			std::cout << "use WASD to move" << std::endl;
			std::cout << "use J to attack, E to talk with NPC, I for check inventory!" << std::endl;
			std::cout << "use Q to quit... and one more letter... what it is?" << std::endl;
			flag += 1; // start output message
		}

		field.moveEnemies();
		field.combat();
		if (!dragon->getCanMove())
		{
			int new_fire_count = dragon->getFireCount() + 1;
			dragon->setFireCount(new_fire_count);
		}
		if (dragon->getFireCount() == 6)
		{
			int new_fire_count = 0;
			field.setPWasSeenD(false);
			dragon->setFireCount(new_fire_count);
			dragon->setCanMove(true);
		}
		field.draw(); // draw the field
		player.UpdateAttackVisual(field, field.getEnemies());
		if (player.getDashFlag())
		{
			player.getDash()->UpdateDashVisual();
		}
		
		for (auto& enemy : field.getEnemies())
		{
			std::cout << enemy->getName() << " HP:" << enemy->getHealth() <<std::endl;
		}
		std::cout << "Your Level: "<< player.getLevel() << "; your HP:" << player.getHealth() << "; your Damage:" << player.getDamage() <<"; your EXP: " << player.getExp() << "; your Gold: " << player.getGold() << std::endl;

		if (!player.isAlive())
		{
			endGame = true;
			break;
		}
		if (!dragon->isAlive())
		{
			dragon->UpdateFireVisual(field, player);
		}
		if (isdigit(input))
		{

			field.Buy(input);
		}
		input = tolower(getchar()); // get the input letter from keyboard
		if (input == 'q')
		{
			endGame = true;
			disableRawMode(); // return settings as it was
			break;
		}
		// for walking use only WASD
		if (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'j')
		{
			if (input != 'j')
			{
				field.setInputSymb(input);
			}
			std::cout << "\033[2J\033[1;1H"; // clear the console
			field.Movement(input); // processing the input value
		}
		else if (input == 'e' || input == 'i')
		{
			field.Interaction(input);
		}
		else
		{
			std::cout << "\033[2J\033[1;1H"; // clear the console
		}

		if (player.getPersevFlag())
		{
			player.getPersev()->use(player);
		}
		if (player.getBestExpFlag())
		{
			player.getBestExp()->use(player);
		}
		if (player.getHealFlag())
		{
			player.getHeal()->use(player);
		}
		if (player.getDashFlag() && input == 'k')
		{
			player.getDash()->use(player);
		}
		
		if (player.getExp() >= 10)
		{
			player.levelUp();
		}
		if (player.getExp() >= 25)
		{
			player.levelUp();
		}
	}
}

void Game::Level_1()
{
	if (!endGame)
	{
		unsigned int health = 100;
		player.setHealth(health);
		std::cout << "\033[2J\033[1;1H";
		std::cout << "Don't approach the enemies if you don't want to get dirty! \nbut then how can they be defeated?" << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		std::cout << "\033[2J\033[1;1H";
		std::cout << "Welcome to the abandoned lands..." << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		field.banditSpawn(2, 2);
		field.banditSpawn(5, 5);
		field.banditSpawn(27, 3);
		field.banditSpawn(22, 7);
		if (!endGame)
		{
			start_game();
		}
		completeLevel = false;
	}
}

void Game::startVillage()
{
	if (!endGame)
	{
		std::cout << "\033[2J\033[1;1H";
		std::cout << "Welcome to the old... Old village!" << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		std::cout << "\033[2J\033[1;1H";
		std::cout << "WOW!!! who?.. who is it?" << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		field.elderSpawn(3, 12);
		field.traderSpawn(27, 12);
		if (!endGame)
		{
			start_game();
		}
		completeLevel = false;
		field.getElder()->setDialogueComplete(false);
	}
}

void Game::Level_2()
{
	if (!endGame)
	{
		std::cout << "\033[2J\033[1;1H";
		std::cout << "What?! What is it..?" << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		std::cout << "\033[2J\033[1;1H";
		std::cout << "new enemies!" << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		field.slimeSpawn(7, 2);
		field.banditSpawn(5, 5);
		field.banditSpawn(17, 3);
		field.slimeSpawn(25, 7);
		if (!endGame)
		{
			start_game();
		}
		completeLevel = false;
		field.getElder()->setDialogueComplete(false);
	}
}

void Game::Level_3()
{
	if (!endGame)
	{
		unsigned int health = 100;
		player.setHealth(health);
		field.getElder()->setMission2(true);
		start_game();
		if (!endGame)
		{
			field.yardDragonSpawn(15, 3);
			start_game();
		}
		if (!endGame)
		{
			start_game();
		}
	}
}