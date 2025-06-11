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

int jacobstahl(int level)
{
	return round((pow(2, level + 1) + pow(-1, level)) / 3);
}

void initPendVect(std::vector<int>& main, std::vector<int>& pend, int size)
{
	int pos = 2 * size;
	while(pos + size <= static_cast<int>(main.size()))
	{
		int i = 0;
		while (i != size)
		{
			pend.push_back(main[pos]);
			main.erase(main.begin() + pos);
			i++;
		}
		pos += size;
	}
}

void binarySearchVect(std::vector<int>& main, std::vector<int>& pend, std::vector<int>::iterator elemPend, int searchRange, int pairSize)
{
    int left = 0;
    int right = searchRange * pairSize;
    int target = *(elemPend);
    
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (main[mid] < target)
            left = mid + pairSize;
        else
            right = mid;
    }
    std::vector<int>::iterator insertPos = main.begin() + left;
    main.insert(insertPos, elemPend - pairSize + 1, elemPend + 1);
    pend.erase(elemPend - pairSize + 1, elemPend + 1);
}

void insertToMainVect(std::vector<int>& main, std::vector<int>& pend, int size)
{
	int actJacob, prevJacob, rangeInsert, rangeSearch, level;
	std::vector<int>::iterator elemPend;
	level = 2;
	while (!pend.empty())
	{
		actJacob = jacobstahl(level);
		prevJacob = jacobstahl(level - 1);
		rangeInsert = actJacob - prevJacob;
		rangeSearch = actJacob + prevJacob - 1;
		while (rangeInsert && !pend.empty())
		{
			elemPend = pend.begin() + size * rangeInsert - 1;
			if (elemPend >= pend.end())
				elemPend = pend.end() - 1;
			binarySearchVect(main, pend, elemPend, rangeSearch, size);
			rangeInsert--;
		}
		level++;
	}
}

void divideVect(std::vector<int>& vect, long unsigned int size)
{
	std::vector<int>::iterator firstElem = vect.begin() + (size / 2) - 1;
	std::vector<int>::iterator secondElem = vect.begin() + size - 1;
	std::vector<int> pend;
	while (firstElem + size / 2 <= vect.end())
	{
		if (*firstElem > *secondElem)
			std::swap_ranges(firstElem - (size / 2 - 1), secondElem - size / 2 + 1, secondElem - size/2 + 1);
		firstElem += size;
		secondElem += size;
	}
	if (size <= vect.size() / 2)
		divideVect(vect, size * 2);
	initPendVect(vect, pend, size);
	insertToMainVect(vect, pend, size);
}

std::vector<int> PmergeVect(int ac, char **av)
{
	std::vector<int> vect;
	std::vector<int>pend;
	for (int i = 1; i < ac; i++)
		vect.push_back(std::atoi(av[i]));
	divideVect(vect, 2);
	return vect;
}

void initPendDeq(std::deque<int>& main, std::deque<int>& pend, int size)
{
	std::deque<int>::iterator firstElem = main.begin() + 2 * size;
	while(firstElem + size <= main.end())
	{
		int i = 0;
		while (i != size)
		{
			pend.push_back(*firstElem);
			main.erase(firstElem);
			i++;
		}
		firstElem += size;
	}
}

void binarySearchDeq(std::deque<int>& main, std::deque<int>& pend, std::deque<int>::iterator elemPend, int searchRange, int pairSize)
{	
	int left = 0;
    int right = searchRange * pairSize;
    int target = *(elemPend);
    
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (main[mid] < target)
            left = mid + pairSize;
        else
            right = mid;
    }
    std::deque<int>::iterator insertPos = main.begin() + left;
    main.insert(insertPos, elemPend - pairSize + 1, elemPend + 1);
    pend.erase(elemPend - pairSize + 1, elemPend + 1);
} 

void insertToMainDeq(std::deque<int>& main, std::deque<int>& pend, int size)
{
	int actJacob, prevJacob, rangeInsert, rangeSearch, level;
	std::deque<int>::iterator elemPend;
	level = 2;
	while (!pend.empty())
	{
		actJacob = jacobstahl(level);
		prevJacob = jacobstahl(level - 1);
		rangeInsert = actJacob - prevJacob;
		rangeSearch = actJacob + prevJacob - 1;
		while (rangeInsert && !pend.empty())
		{
			elemPend = pend.begin() + size * rangeInsert - 1;
			if (elemPend >= pend.end())
				elemPend = pend.end() - 1;
			binarySearchDeq(main, pend, elemPend, rangeSearch, size);
			rangeInsert--;
		}
		level++;
	}
}

void divideDeq(std::deque<int>& deq, long unsigned int size)
{
	std::deque<int>::iterator firstElem = deq.begin() + (size / 2) - 1;
	std::deque<int>::iterator secondElem = deq.begin() + size - 1;
	std::deque<int> pend;
	int level;
	while (firstElem + size <= deq.end())
	{
		if (*firstElem > *secondElem)
			std::swap_ranges(firstElem - (size / 2 - 1), secondElem - size / 2 + 1, secondElem - size / 2 + 1);
		firstElem += size;
		secondElem += size;
		level++;
	}
	if (size <= deq.size() / 2)
		divideDeq(deq, size * 2);
	initPendDeq(deq, pend, size);
	insertToMainDeq(deq, pend, size);
}

std::deque<int> PmergeDeque(int ac, char** av)
{
	std::deque<int> deq;
	for (int i = 1; i < ac; i++)
		deq.push_back(std::atoi(av[i]));
	divideDeq(deq, 2);
	return deq;
}

