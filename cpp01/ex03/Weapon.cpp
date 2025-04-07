#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type): type(type)
{

}

Weapon::~Weapon()
{

}

void Weapon::setType(std::string str)
{
	type = str;
}

const std::string& Weapon::getType()
{
	return type;
}
