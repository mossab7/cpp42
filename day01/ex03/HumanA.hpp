#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	Weapon &weapon;
	std::string name;

	public :
		void attack();
		HumanA( Weapon &wp, std::string nm);
};

#endif //HUMANA_HPP
