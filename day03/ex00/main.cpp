#include "ClapTrap.hpp"

int main() 
{
    ClapTrap claptrap1("Clappy");
    ClapTrap claptrap2(claptrap1);
    
    claptrap1.attack("target1");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(3);
    
    ClapTrap claptrap3;
    claptrap3 = claptrap1;
    
    claptrap3.attack("target2");
    
    return 0;
}