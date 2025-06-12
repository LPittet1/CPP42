#include <string>
#include <climits>
#include <ctime>
#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "No arguments given." << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		long val = std::strtol(av[i], 0 , 10);
		if (val < 0 || val > INT_MAX)
		{
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
	}
	std::clock_t timeVectorStart = std::clock();
	std::vector<int> vect = PmergeVect(ac, av);
	std::clock_t timeVectorEnd = std::clock();
	std::clock_t timeDequeStart = std::clock();
	//std::deque<int> deq = PmergeDeque(ac, av);
	std::clock_t timeDequeEnd = std::clock();
	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i];
		if (i != ac)
			std::cout << " ";
	}
	std::cout << std::endl << "After: ";
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vect.end())
			std::cout << " ";
	}
	std::cout << std::endl << "Time to process a range of " << ac - 1;
	std::cout << " elements with std::vector: ";
	std::cout << 1000.0 * (timeVectorEnd - timeVectorStart) / CLOCKS_PER_SEC << "ms";
	std::cout << std::endl << "Time to process a range of " << ac - 1;
	std::cout << " elements with std::deque: ";
	std::cout << 1000.0 * (timeDequeEnd - timeDequeStart) / CLOCKS_PER_SEC << "ms";
}
