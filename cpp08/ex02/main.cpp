#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::vector<int> comp;
	comp.push_back(5);
	mstack.push(5);
	comp.push_back(17);
	mstack.push(17);
	std::cout << mstack.top()  << " " << comp.back() << std::endl;
	mstack.pop();
	comp.pop_back();
	std::cout << mstack.size() <<  " " << comp.size() << std::endl;
	comp.push_back(3);
	mstack.push(3);
	comp.push_back(5);
	mstack.push(5);
	comp.push_back(737);
	mstack.push(737);
	comp.push_back(0);
	mstack.push(0);
	const MutantStack<int> test(mstack);
	MutantStack<int>::citerator cm = test.begin();
	MutantStack<int>::citerator ce = test.end();
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::vector<int>::iterator cit = comp.begin();
	std::vector<int>::iterator cite = comp.end();
	++it;
	--it;
	++cit;
	--cit;
	while (it != ite && cit != cite && cm != ce)
	{
		std::cout << *it  << " " << *cit  << " " << *cm << std::endl;
		++it;
		++cit;
		++cm;
	}
	std::stack<int> s(mstack);
	return 0;
}