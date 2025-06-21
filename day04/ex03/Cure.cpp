#include "Cure.hpp"

Cure::Cure(const Cure &other) : AMateria(other._type)
{
    std::cout << "Cure materia is copied" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure materia is created" << std::endl;
}

Cure::~Cure()
{
    std::cout << "destructor is called for cure materia" << std::endl;
}

Cure *Cure::clone() const
{
    return (new Cure(*this));
}


void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}