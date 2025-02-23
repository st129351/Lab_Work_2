//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include <gtest/gtest.h>
#include "MyClass.h"

TEST(MyClass, TotalHealth)
{
	MyClass knight(100, 150);
	EXPECT_EQ(knight.TotalHealth(), 250);
}
