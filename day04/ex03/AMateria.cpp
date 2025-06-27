#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << "AMateria of type " << _type << " copied" << std::endl;
}
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		_type = other._type;
		std::cout << "AMateria of type " << _type << " assigned" << std::endl;
	}
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria of type " << _type << " created" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}
