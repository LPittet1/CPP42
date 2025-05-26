#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void subject_provided_test(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void adding_range(void)
{
	Span sp = Span(15000);

	std::list<int> li;
	std::srand(time(0));
	for (int i = 0; i < 15000; i++)
	{
		li.push_back(std::rand());
	}
	sp.addNumber(li.begin(), li.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	subject_provided_test();
	adding_range();
	return 0;
}