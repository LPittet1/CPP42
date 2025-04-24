#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap& cpy);
	DiamondTrap& operator=(DiamondTrap& rhs);
	~DiamondTrap();
	void attack(std::string target);
	void whoAmI();
};


