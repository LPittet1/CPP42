#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& cpy);
	ScavTrap& operator=(ScavTrap& rhs);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};

