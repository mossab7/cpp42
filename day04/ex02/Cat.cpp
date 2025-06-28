#include "Cat.hpp"

Cat::Cat() : IAnimal("Cat")
{
	_brain = new Brain();
	if (!_brain)
	{
		std::cerr << "Memory allocation failed for Brain." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Cat created." << std::endl;
}
Cat::Cat(const std::string &type) : IAnimal(type)
{
	std::cout << "Cat of type " << _type << " created." << std ::endl;
}
Cat::Cat(const Cat &other) : IAnimal(other)
{
	_brain = new Brain(*other._brain);
	if (!_brain)
	{
		std::cerr << "Memory allocation failed for Brain." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Cat copied." << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		IAnimal::operator=(other);
		delete _brain;  
		_brain = new Brain(*other._brain);
		if (!_brain)
		{
			std::cerr << "Memory allocation failed for Brain." << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	return *this;
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat of type " << _type << " destroyed." << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "Meow! I am a " << _type << "." << std::endl;
}
