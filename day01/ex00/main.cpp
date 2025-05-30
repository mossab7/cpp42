#include "Zombie.hpp"

int main(void)
{
	Zombie::randomChamp("idk");
	Zombie *otherZombie = Zombie::newZombie("otherZombie");
	otherZombie->announce();
	delete otherZombie;
	return (0);
}
