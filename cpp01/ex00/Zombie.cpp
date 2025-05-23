#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << " :  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << " raised from the dead" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " died" << std::endl;
}