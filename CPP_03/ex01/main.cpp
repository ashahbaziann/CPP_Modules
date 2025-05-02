#include "ClapTrap.hpp"

int main()
{
    ClapTrap ClapTrapOne("ClapTrapOne");
    ClapTrap ClapTrapTwo("ClapTrapTwo");

    ClapTrapOne.attack("ClapTrapTwo");
    ClapTrapTwo.attack("ClapTrapOne");

    ClapTrapOne.takeDamage(5);
    ClapTrapTwo.takeDamage(3);

    ClapTrapOne.beRepaired(3);
    ClapTrapTwo.beRepaired(5);

    ClapTrapOne.attack("ClapTrapTwo");
}