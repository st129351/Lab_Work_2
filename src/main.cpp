//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include <gtest/gtest.h>
#include "MyClass.h"

int main()
{
	MyClass hollow_knight(100, 150);
	std::cout << "Total health of HK: " << hollow_knight.TotalHealth() << std::endl;
	std::cout << "Here will be my game :)" << std::endl;

	return 0;
}