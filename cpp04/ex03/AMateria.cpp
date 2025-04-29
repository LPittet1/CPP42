
#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	
}

AMateria::AMateria(const std::string& type): type(type)
{
	
}

AMateria::AMateria(const AMateria& cpy): type(cpy.type)
{
	
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

AMateria::~AMateria()
{

}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
}

const std::string& AMateria::getType() const
{
	return type;
}