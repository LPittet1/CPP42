#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong animal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy): type(cpy.type)
{
	std::cout << "Wrong animal copy" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		std::cout << "Wrong animal assignment operator" << std::endl;
	}
	return *this;
}

void WrongAnimal::makeSound()
{
	std::cout << "wrong animal does not make sound" << std::endl;
}

std::string WrongAnimal::getType()
{
	return type;
}