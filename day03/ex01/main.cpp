#include "ScavTrap.hpp"

int main() 
{
    ScavTrap scavtrap1("Scavvy");
    ScavTrap scavtrap2(scavtrap1);
    ClapTrap *robot = new ScavTrap("ScavBot");
    
    scavtrap1.attack("target1");
    scavtrap2.takeDamage(5);
    scavtrap2.beRepaired(3);
    robot->attack("target3");
    ScavTrap scavtrap3;
    scavtrap3 = scavtrap1;
    
    scavtrap3.attack("target2");
    scavtrap3.guardGate();
    delete robot;
    return 0;
}