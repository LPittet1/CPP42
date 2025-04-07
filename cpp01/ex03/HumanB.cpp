#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{

}
HumanB::~HumanB()
{

}
void HumanB::setWeapon(Weapon &wpn)
{
	this->weapon = &wpn;
}

void HumanB::attack()
{
	if (!weapon)
	{
		std::cout << name << " cannot attack with their bare hands." << std::endl;
		return;
 	}
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}