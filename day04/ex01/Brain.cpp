#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created." << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = "Empty idea";
	}
}
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i];
	}
}
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain destroyed." << std::endl;
}
void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
	else
	{
		std::cerr << "Index out of bounds!" << std::endl;
	}
}
std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return ideas[index];
	}
	else
	{
		std::cerr << "Index out of bounds!" << std::endl;
		return "";
	}
}
