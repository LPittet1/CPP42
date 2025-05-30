#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please input your operation as a single string" << std::endl;
		return 1;
	}
	std::stringstream input(av[1]);
	RPN(input);
}