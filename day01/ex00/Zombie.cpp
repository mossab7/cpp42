#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie( std::string nm )
{
	name = nm;
}

Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return *this;
}

Zombie::Zombie(const Zombie &other)
{
	name = other.name;
}

Zombie::~Zombie()
{
	std::cout << "destructor is callid for " << name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *Zombie::newZombie( std::string name )
{
	Zombie *newZombie;

	newZombie = new Zombie(name);
	return (newZombie);
}

void Zombie::randomChamp( std::string name )
{
	Zombie newZombie(name);

	newZombie.announce();
}
