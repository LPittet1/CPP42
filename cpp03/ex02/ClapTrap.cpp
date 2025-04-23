#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& cpy): name(cpy.name), hitPoint(cpy.hitPoint), energyPoint(cpy.energyPoint), attackDamage(cpy.attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cpy)
	{
		hitPoint = cpy.hitPoint;
		name = cpy.name;
		energyPoint = cpy.energyPoint;
		attackDamage = cpy.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " has not enough energy to attack." << std::endl;
		return;
	}
	if (hitPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead, it cannot attack." << std::endl;
		return;
	}
	energyPoint--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead, it cannot take more damage." << std::endl;
	}
	hitPoint -= amount;
	std::cout << "ClapTrap " << name << " is hit for " << amount << " points of damage taken." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " has not enough energy to be repaired." << std::endl;
		return;
	}
	energyPoint--;
	hitPoint += amount;
	std::cout << "ClapTrap " << name << " is being repaired for " << amount << " hit points!" << std::endl;
}