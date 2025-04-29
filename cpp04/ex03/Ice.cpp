
#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice")
{

}

Ice::Ice(const Ice& cpy): AMateria(cpy)
{

}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}