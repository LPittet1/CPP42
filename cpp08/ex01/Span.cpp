
#include <iostream>
#include <algorithm>
#include <exception>
#include "Span.hpp"


Span::Span(unsigned int N): N(N), cont()
{

}

Span::Span(const Span& cpy): N(cpy.N), cont(cpy.cont)
{

}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		N = rhs.N;
		cont = rhs.cont;
	}
	return *this;
}

Span::~Span()
{
	
}

void Span::addNumber(int val)
{
	if (cont.size() < N)
		cont.push_back(val);
	else
		std::cout << "Couldn't add " << val << " because this span is full." << std::endl;
}


int Span::shortestSpan(void) const
{
	if (cont.size() < 2)
		throw std::logic_error("Not enough elements to get a span");
	std::vector<int> temp = cont;
	std::vector<int> diff;
	std::sort(temp.begin(), temp.end());
	for (std::vector<int>::iterator it = temp.begin() + 1; it != temp.end(); it++)
	{
		diff.push_back(*it - *(it - 1));
	}
	return *std::min_element(diff.begin(), diff.end());
}

int Span::longestSpan(void) const
{
	if (cont.size() < 2)
		throw std::logic_error("Not enough elements to get a span");
	return *std::max_element(cont.begin(), cont.end()) - *std::min_element(cont.begin(), cont.end());
}