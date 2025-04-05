#include "Zombie.hpp"

int main()
{
    Zombie main("Ulysse");
    Zombie *alloc = newZombie("Hercule");
    randomChump("temp");

    main.announce();
    alloc->announce();
    delete alloc;
}