#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << " :  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << " raised from the dead" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " died" << std::endl;
}

void Zombie::setName(std::string str)
{
	name = str;
}