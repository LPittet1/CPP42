#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Eudes");
	ClapTrap trap("Gilles");

	clap.beRepaired(1);
	for (int i = 0; i < 10; i++)
	{
		clap.attack("Etienne");
	}
	clap.beRepaired(2);
	trap.takeDamage(10);
	trap.attack("Pierre");
	trap.beRepaired(1);
	trap.attack("Pierre");
}