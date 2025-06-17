#include "DiamondTrap.hpp"

int main() 
{
    DiamondTrap diamondTrap1("Diamondy");
    DiamondTrap diamondTrap2(diamondTrap1);
    ClapTrap *robot = new DiamondTrap("DiamondBot");
    
    diamondTrap1.attack("target1");
    diamondTrap2.ScavTrap::takeDamage(5);
    diamondTrap2.ScavTrap::beRepaired(3);
    robot->attack("target3");
    DiamondTrap diamondTrap3;
    diamondTrap3 = diamondTrap1;
    
    diamondTrap3.attack("target2");
    diamondTrap3.whoAmI();
    
    delete robot;
    return 0;
}