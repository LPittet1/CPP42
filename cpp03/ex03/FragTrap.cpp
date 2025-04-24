#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default contructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(FragTrap& rhs): ClapTrap(rhs)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		std::cout << "FragTrap assignment operator called" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage." << std::endl;
		energyPoint--;
		return;
	}
	if (energyPoint < 0)
	{
		std::cout << "ScavTrap " << name << " has not enough energy to attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " is dead and cannot attack" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Who wants a high five ✋" << std::endl;
}