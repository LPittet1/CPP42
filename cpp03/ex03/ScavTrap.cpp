#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& cpy): ClapTrap(cpy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		std::cout << "ScavTrap assignment operator called" << std::endl;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage." << std::endl;
		energyPoint--;
		return;
	}
	if (energyPoint <= 0)
	{
		std::cout << "ScavTrap " << name << " has not enough energy to attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " is dead and cannot attack" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}