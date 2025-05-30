#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>


class Zombie
{
	std::string name;
	public :
		Zombie();
		Zombie( std::string nm );
		Zombie &operator=( const Zombie &other );
		Zombie( const Zombie &other );
		~Zombie();
		void announce( void );
		static Zombie *newZombie( std::string name );
		static void randomChamp( std::string name );
};

#endif //ZOMBIE_HPP
