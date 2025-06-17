#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : FragTrap("Default"), ScavTrap("Default"), _name("Default") 
{
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}
DiamondTrap::DiamondTrap(std::string name)
    : FragTrap(name + "_frag"), ScavTrap(name + "_scav"), _name(name) 
{
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : FragTrap(other), ScavTrap(other), _name(other._name) 
{
    std::cout << "DiamondTrap copied." << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other) {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}
void DiamondTrap::attack(const std::string &target) 
{
    if (ScavTrap::_energyPoints > 0 && FragTrap::_hitPoints > 0) {
        std::cout << "DiamondTrap " << _name << " attacks " << target 
                  << ", causing " << FragTrap::_attackDamage << " points of damage!" << std::endl;
        ScavTrap::_energyPoints--;
    } else {
        std::cout << "DiamondTrap " << _name << " cannot attack!" << std::endl;
    }
}
void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name << ". My FragTrap name is " 
              << FragTrap::_name << " and my ScavTrap name is " 
              << ScavTrap::_name << "." << std::endl;
}