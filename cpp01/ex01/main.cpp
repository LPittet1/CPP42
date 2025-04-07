#include "Zombie.hpp"

int main()
{
	int N = 6;
	
	Zombie* horde = zombieHorde(N, "Alceste");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}