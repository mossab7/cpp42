#include "Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon(const Weapon &other)
{
	type = other.type;
}

Weapon& Weapon::operator=(const Weapon &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void Weapon::setType( std::string weapon )
{
	type = weapon;
}

std::string& Weapon::getType()
{
	return (type);
}

Weapon::Weapon(std::string weapon)
{
	type = weapon;
}

Weapon::~Weapon()
{
}
