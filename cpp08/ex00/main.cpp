#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vect;
	std::deque<int> deq;
	std::list<int> li;
	
	for (int i = 1; i < 1254; i += i % 7)
	{
		vect.push_back(i);
		deq.push_back(i);
		li.push_front(i);
	}
	std::vector<int>::iterator vectIt;
	std::deque<int>::iterator deqIt;
	std::list<int>::iterator liIt;
	vectIt = ::easyfind(vect, 1);
	deqIt = ::easyfind(deq, 9);
	liIt = ::easyfind(li, 1002);
	if (vectIt == vect.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << *vectIt << std::endl;
	if (deqIt == deq.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << *deqIt << std::endl;
	if (liIt == li.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << *liIt << std::endl;
	vectIt = ::easyfind(vect, 7);
	deqIt = ::easyfind(deq, 1001);
	liIt = ::easyfind(li, 1004);
	if (vectIt == vect.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << *vectIt << std::endl;
	if (deqIt == deq.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << *deqIt << std::endl;
	if (liIt == li.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << *liIt << std::endl;
}