#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
	brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		this->brain->addIdea(cpy.brain->getIdeas(i));
	}
	std::cout << "Dog copy" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		std::cout << "Dog assignment operator" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			this->brain->addIdea(rhs.brain->getIdeas(i));
		}
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOOUUAF" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}