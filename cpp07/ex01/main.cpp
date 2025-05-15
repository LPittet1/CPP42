#include "iter.hpp"
#include <iostream>
#include <cmath>

int main()
{
	std::string test[10];
	double testint[10];
	for (int i = 0; i < 10; i++)
	{
		test[i] = 'a' + i;
		testint[i] = i;
		std::cout << test[i] << std::endl;
		std::cout << testint[i] << std::endl;
	}
	iter(test, 10, doub);
	iter(testint, 10, sqrt);
	for (int i = 0; i < 10; i++)
	{
		std::cout << test[i] << std::endl;
		std::cout << testint[i] << std::endl;
	}
}