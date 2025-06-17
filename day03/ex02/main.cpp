#include "FragTrap.hpp"

int main() 
{
    FragTrap fragtrap1("Fraggy");
    FragTrap fragtrap2(fragtrap1);
    ClapTrap *robot = new FragTrap("FragBot");
    
    fragtrap1.attack("target1");
    fragtrap2.takeDamage(5);
    fragtrap2.beRepaired(3);
    robot->attack("target3");
    FragTrap fragtrap3;
    fragtrap3 = fragtrap1;
    
    fragtrap3.attack("target2");
    fragtrap3.highFivesGuys();
    delete robot;
    return 0;
}