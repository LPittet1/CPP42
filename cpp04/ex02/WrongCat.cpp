#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat constructor" << std::endl;
	type = "Wrong cat";
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongCat copy" << std::endl;
	type = "Wrong cat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
		std::cout << "WrongCat assignment operator" << std::endl;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat noises" << std::endl;
}
