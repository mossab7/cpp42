#include "IAnimal.hpp"

IAnimal::IAnimal() : _type("Unknown")
{
	std::cout << "Animal created." << std::endl;
}
IAnimal::IAnimal(const std::string &type) : _type(type)
{
	std::cout << "Animal of type " << _type << " created." << std::endl;
}
IAnimal::IAnimal(const IAnimal &other) : _type(other._type)
{
	std::cout << "Animal copied." << std::endl;
}
IAnimal &IAnimal::operator=(const IAnimal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}
IAnimal::~IAnimal()
{
	std::cout << "Animal of type " << _type << " destroyed." << std ::endl;
}
std::string IAnimal::getType() const
{
	return _type;
}
