#include "Ice.hpp"

Ice::Ice(const Ice &other) : AMateria(other._type)
{
    std::cout << "ice materia is copied" << std::endl;
}
Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Ice::Ice() : AMateria("ice")
{
    std::cout << "ice materia is created" << std::endl;
}

Ice::~Ice()
{
    std::cout << "destructor is called for ice materia" << std::endl;
}

Ice *Ice::clone() const
{
    return new Ice(*this);
}


void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}