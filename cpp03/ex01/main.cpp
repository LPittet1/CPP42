#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Etienne");
	scav.beRepaired(1);
	scav.attack("Francois");
	scav.takeDamage(10);
	scav.guardGate();
}