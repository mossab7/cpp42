#include "FragTrap.hpp"

FragTrap::FragTrap() 
    : ClapTrap() 
{
    std::cout << "FragTrap created." << std::endl;
}
FragTrap::FragTrap(std::string name) 
    : ClapTrap(name) 
{
    std::cout << "FragTrap " << name << " created." << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) 
    : ClapTrap(other) 
{
    std::cout << "FragTrap copied." << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other) 
{
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}
FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destroyed." << std::endl;
}
void FragTrap::attack(const std::string &target) 
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "FragTrap " << _name << " cannot attack!" << std::endl;
    }
}
void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}