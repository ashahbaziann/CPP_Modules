#include "Zombie.hpp"

int main(void)
{
    Zombie *horde = zombieHorde(3, "zombik");
    int i = 0;
    while (i < 3)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}