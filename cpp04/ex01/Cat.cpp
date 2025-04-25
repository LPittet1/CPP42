#include "Cat.hpp"
#include <iostream>

Cat::Cat() 
{
	std::cout << "Cat constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
	std::cout << "Cat copy" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		std::cout << "Cat assignment operator" << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meooooow" << std::endl; 
}
