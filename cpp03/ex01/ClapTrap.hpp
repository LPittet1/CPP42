#pragma once
#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int hitPoint;
	int energyPoint;
	int attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& cpy);
	ClapTrap& operator=(ClapTrap& cpy);
	~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

