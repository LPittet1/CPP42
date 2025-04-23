#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	energyPoint = 50;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	energyPoint = 50;
}

DiamondTrap::DiamondTrap(DiamondTrap& cpy): ScavTrap(cpy), FragTrap(cpy)
{
	std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "name = " << name << std::endl;
	std::cout << "ClapTrap name = " << ClapTrap::name << std::endl;
}