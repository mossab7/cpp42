#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombies = Zombie::zombieHorde(4,"zombies");
	for (int i = 0 ; i < 4; i++)
		Zombies[i].announce();

	delete[] Zombies;
	return (0);
}
