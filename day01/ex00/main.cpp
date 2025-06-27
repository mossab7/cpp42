#include "Zombie.hpp"

int main(void)
{
	Zombie *pointerzombie = Zombie::newZombie("pointerzombie");
	Zombie &refrencezombie = *Zombie::newZombie("refrencezombie");

	Zombie::randomChamp("normalzombie");
	pointerzombie->announce();
	refrencezombie.announce();
	delete pointerzombie;
	delete &refrencezombie;
	return (0);
}
