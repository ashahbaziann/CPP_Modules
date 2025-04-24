#include "Zombie.hpp"

int main(void)
{
    Zombie z1("Zombie_1");
    z1.announce();
    randomChump("Zombie_2");
    Zombie *z3 = newZombie("Zombie_3");
    z3->announce();
    delete z3;
}