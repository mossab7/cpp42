#include "HumanB.hpp"

HumanB::HumanB(std::string nm) : name(nm)  {}

void HumanB::setWeapon(Weapon &wp)
{
	weapon = &wp;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their " << std::endl;
}
