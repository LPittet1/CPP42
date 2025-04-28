#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& cpy) : ideas(cpy.ideas)
{
	std::cout << "Brain copy constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Brain assignment operator" << std::endl;
		*ideas = *rhs.ideas;
	}
	return *this;
}

std::string Brain::getIdeas(int i)
{
	return ideas[i];
}

void Brain::addIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			return;
		}
	}
	std::cout << "Brain is full it can't have new ideas" << std::endl;
}

void Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!ideas[i].empty())
			std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
	}
}