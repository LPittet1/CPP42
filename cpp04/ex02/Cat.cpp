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
