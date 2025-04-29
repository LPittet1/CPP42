
#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure")
{

}

Cure::Cure(const Cure& cpy): AMateria(cpy)
{

}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	
	}
	return *this;
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s name *" << std::endl;
}