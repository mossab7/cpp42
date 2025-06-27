#ifndef IANIMAL_HPP
#define IANIMAL_HPP

#include <iostream>
#include <cstdlib>

class IAnimal
{
protected:
	std::string _type;

public:
	IAnimal();
	IAnimal(const std::string &type);
	IAnimal(const IAnimal &other);
	IAnimal &operator=(const IAnimal &other);
	virtual ~IAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif // IANIMAL_HPP
