#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Use exactly one argument" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}