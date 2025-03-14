//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include "MyClass.h"

MyClass::MyClass(int a, int b) : health(a), armor(b) {}

int MyClass::TotalHealth()
{
	int total = health + armor;

	return total;
}