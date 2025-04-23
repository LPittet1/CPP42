#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default contructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
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

void FragTrap::highFivesGuys()
{
	std::cout << "Who wants a high five ✋" << std::endl;
}