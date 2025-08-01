#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure &operator=(const Cure &other);
	Cure(const Cure &other);
	Cure *clone() const;
	void use(ICharacter &target);
};

#endif // CURE_HPP
