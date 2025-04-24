#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& cpy) : type(cpy.type)
{
	std::cout << "Animal copy" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Animal assignment operator" << std::endl;
		type = rhs.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "animal destructor" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "animal make no defined sound" << std::endl;
}