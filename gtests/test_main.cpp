//Lichkovaha Daniil
//st129351@student.spbu.ru
//LabWork2

#include <gtest/gtest.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	// set variable enviroment for tests
	putenv((char*)"RUNNING_TESTS=1");
	
	// removing unnecessary gaps in the test output
	testing::GTEST_FLAG(brief) = true;
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}