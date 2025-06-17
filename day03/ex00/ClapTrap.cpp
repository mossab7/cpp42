#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " created." << std::endl;
}
ClapTrap::ClapTrap(std::string _name)
    : _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " created." << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {}
ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}
ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}


void ClapTrap::attack(const std::string &target) 
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount) 
{
    if (_hitPoints > amount) {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
    } else {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself for " 
                  << amount << " points! Current hit points: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " cannot be repaired!" << std::endl;
    }
}