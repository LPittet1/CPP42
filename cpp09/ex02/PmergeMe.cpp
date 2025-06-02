#include <cmath>
#include "PmergeMe.hpp"

int maxNumberOfComparison(int numVal)
{
	int num = 0;
	for (int i = 1; i <= numVal; ++i)
	{
		double val = (3.0 / 4.0) * i;
		num += static_cast<int>(ceil(log2(val)));
	}
	return num;
}

void divideVect(std::vector<int> vect, int size)
{
	(void)size;
	(void)vect;	
}

std::vector<int> PmergeVect(int ac, char **av)
{
	std::vector<int> vect;
	for (int i = 1; i < ac; i++)
		vect.push_back(std::atoi(av[i]));
	for (int level = 1; pow(2, level) < ac; level++)
	{
		divideVect(vect, pow(2, level));
	}
	return vect;
}

std::deque<int> PmergeDeque(int ac, char** av)
{
	std::deque<int> deq;
	for (int i = 1; i < ac; i++)
		deq.push_back(std::atoi(av[i]));
	return deq;
}

