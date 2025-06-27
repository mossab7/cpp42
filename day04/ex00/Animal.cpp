#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "Animal created." << std::endl;
}
Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal of type " << _type << " created." << std::endl;
}
Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copied." << std::endl;
}
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}
Animal::~Animal()
{
	std::cout << "Animal of type " << _type << " destroyed." << std ::endl;
}
std::string Animal::getType() const
{
	return _type;
}
void Animal::makeSound() const
{
	std::cout << "Animal sound! I am a " << _type << "." << std::endl;
}
