#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(std::string const &type);
	virtual ~AMateria() {}
	AMateria &operator=(const AMateria &other);
	AMateria(const AMateria &other);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // AMateria.hpp
