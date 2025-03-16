//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include <gtest/gtest.h>
#include "Player.h"
#include "Inventory.h"
#include "Amulet.h"

TEST(Player, LevelUp)
{
	Player player;
	unsigned int initialDamage = player.getDamage();
	player.levelUp();
	EXPECT_EQ(player.getDamage(), initialDamage + 10);
}

TEST(Player, ExpAndGold)
{
	Player player;
	EXPECT_EQ(player.getExp(), 0);
	EXPECT_EQ(player.getGold(), 0);
}

TEST(Inventory, SizeLimit)
{
	Player player;
	Inventory inventory(player);
	// Здесь можно добавить тесты для проверки лимита размера инвентаря
}
