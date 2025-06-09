#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- Creating DiamondTrap ---\n";
    DiamondTrap d1("Shiny");

    std::cout << "\n--- Testing whoAmI ---\n";
    d1.whoAmI();

    std::cout << "\n--- Testing attack ---\n";
    d1.attack("BadGuy");

    std::cout << "\n--- Taking damage ---\n";
    d1.takeDamage(20);

    d1.beRepaired(10);

    std::cout << "\n--- Copy constructor test ---\n";
    DiamondTrap d2(d1);
    d2.whoAmI();

    std::cout << "\n--- Assignment operator test ---\n";
    DiamondTrap d3;
    d3 = d1;
    d3.whoAmI();

    std::cout << "\n--- Testing energy depletion ---\n";
    for (int i = 0; i < 99; ++i) {
        d1.attack("Dummy");
    }

    std::cout << "\n--- Final whoAmI calls ---\n";
    d1.whoAmI();
    d2.whoAmI();
    d3.whoAmI();

    std::cout << "\n--- Destructors will now be called automatically ---\n";
    return 0;
}
