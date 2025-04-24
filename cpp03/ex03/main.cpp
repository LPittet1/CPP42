#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("caillou");

	std::cout << std::endl;
	d.beRepaired(1);
	d.attack("Francois");
	d.takeDamage(10);
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();

	std::cout << std::endl;

	DiamondTrap a;
	std::cout << std::endl;

	a = d;

	std::cout << std::endl;
	a.beRepaired(1);
	a.attack("Francois");
	a.takeDamage(10);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();
	std::cout << std::endl;
	// std::cout << std::endl;
	// for (int i = 0; i < 50; i++)
	// {
	// 	a.attack("Pierre");
	// }
}