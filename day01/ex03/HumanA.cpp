#include "HumanA.hpp"

HumanA::HumanA( Weapon &wp, std::string nm) : weapon(wp), name(nm) {}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
