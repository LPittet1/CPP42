#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie
{
private:
    std::string name;
public:
	Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce();
	void setName(std::string str);
};

Zombie *zombieHorde(int N, std::string name);

#endif