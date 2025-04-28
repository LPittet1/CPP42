#include "Cat.hpp"
#include <iostream>

Cat::Cat() 
{
	std::cout << "Cat constructor" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
	brain = new Brain();
	std::cout << "Cat copy" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->brain->addIdea(cpy.brain->getIdeas(i));
	}
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		std::cout << "Cat assignment operator" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			this->brain->addIdea(rhs.brain->getIdeas(i));
		}
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "Meooooow" << std::endl; 
}

Brain* Cat::getBrain() const
{
	return brain;
}
