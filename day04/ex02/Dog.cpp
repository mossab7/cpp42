#include "Dog.hpp"

Dog::Dog() : IAnimal("Dog")
{
	_brain = new Brain();
	if (!_brain)
	{
		std::cerr << "Memory allocation failed for Brain." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Dog created." << std::endl;
}
Dog::Dog(const std::string &type) : IAnimal(type)
{
	std::cout << "Dog of type " << _type << " created." << std::endl;
}
Dog::Dog(const Dog &other) : IAnimal(other)
{
	std::cout << "Dog copied." << std::endl;
	_brain = new Brain(*other._brain);
	if (!_brain)
	{
		std::cerr << "Memory allocation failed for Brain." << std::endl;
		exit(EXIT_FAILURE);
	}
}
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		IAnimal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}
Dog::~Dog()
{
	std::cout << "Dog of type " << _type << " destroyed." << std::endl;
	delete _brain;
}
void Dog::makeSound() const
{
	std::cout << "Woof! I am a " << _type << "." << std::endl;
}
