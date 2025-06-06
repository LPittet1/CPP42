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

void divideVect(std::vector<int>& vect, long unsigned int size)
{
	std::vector<int>::iterator firstElem = vect.begin() + (size / 2) - 1;
	std::vector<int>::iterator secondElem = vect.begin() + size - 1;
	while (firstElem + size < vect.end())
	{
		if (*firstElem > *secondElem)
			std::swap_ranges(firstElem - (size / 2 - 1), secondElem - size / 2 + 1, secondElem - size/2 + 1);
		firstElem += size;
		secondElem += size;
	}
	if (size <= vect.size() / 2)
		divideVect(vect, size * 2);
}

std::vector<int> PmergeVect(int ac, char **av)
{
	std::vector<int> vect;
	for (int i = 1; i < ac; i++)
		vect.push_back(std::atoi(av[i]));
	divideVect(vect, 2);
	return vect;
}

void divideDeq(std::deque<int>& deq, long unsigned int size)
{
	std::deque<int>::iterator firstElem = deq.begin() + (size / 2) - 1;
	std::deque<int>::iterator secondElem = deq.begin() + size - 1;
	while (firstElem + size < deq.end())
	{
		if (*firstElem > *secondElem)
			std::swap_ranges(firstElem - (size / 2 - 1), secondElem - size / 2 + 1, secondElem - size / 2 + 1);
		firstElem += size;
		secondElem += size;
	}
	if (size <= deq.size() / 2)
		divideDeq(deq, size * 2);
}

std::deque<int> PmergeDeque(int ac, char** av)
{
	std::deque<int> deq;
	for (int i = 1; i < ac; i++)
		deq.push_back(std::atoi(av[i]));
	divideDeq(deq, 2);
	return deq;
}

