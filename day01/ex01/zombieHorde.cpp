#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
	Zombie *Zombies;

	Zombies= new Zombie[N];
	for (int i = 0; i < N; i++)
		Zombies[i].setName(name);
	return (Zombies);
}
