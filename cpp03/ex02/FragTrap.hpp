#pragma once
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap& rhs);
	FragTrap& operator=(FragTrap& rhs);
	~FragTrap();
	void highFivesGuys(void);
};
