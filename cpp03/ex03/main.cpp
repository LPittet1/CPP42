#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag("Estelle");
	frag.beRepaired(1);
	frag.attack("Francois");
	frag.takeDamage(10);
	frag.highFivesGuys();
}