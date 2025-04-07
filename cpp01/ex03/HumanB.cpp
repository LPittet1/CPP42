#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{

}
HumanB::~HumanB()
{

}
void HumanB::setWeapon(Weapon wpn)
{
	*weapon = wpn;
}

void HumanB::attack()
{
	if (!weapon)
	{
		std::cout << name << " cannot attack whit their bare hands." << std::endl;
		return;
 	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}