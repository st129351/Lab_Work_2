//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

class MyClass
{
private:
	int health;
	int armor;
public:
	MyClass (int a, int b);

	int TotalHealth();
};

#endif