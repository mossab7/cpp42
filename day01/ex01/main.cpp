#include "Zombie.hpp"

int main(void)
{
	Zombie::randomChamp("idk");
	Zombie *otherZombie = Zombie::newZombie("otherZombie");
	otherZombie->announce();
	Zombie *Zombies = Zombie::zombieHorde(4,"zombies");
	for (int i = 0 ; i < 4; i++)
		Zombies[i].announce();

	delete[] Zombies;
	delete otherZombie;
	return (0);
}
