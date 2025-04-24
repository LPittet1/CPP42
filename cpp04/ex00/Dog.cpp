#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
	std::cout << "Dog copy" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		std::cout << "Dog assignment operator" << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "WOOOUUAF" << std::endl;
}
std::string Dog::getType()
{
	return type;
}