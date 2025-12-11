#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    //std::srand(std::time(nullptr)); // seed rand for RobotomyRequestForm

    try {
        Bureaucrat bob("Bob", 1);         // very high grade
        Bureaucrat alice("Alice", 150);   // very low grade

        std::string home = "home";
        std::string bender = "bender";
        std::string ford = "ford";
        ShrubberyCreationForm shrub(home);
        RobotomyRequestForm robot(bender);
        PresidentialPardonForm pardon(ford);

        std::cout << "\n--- Signing Forms ---\n";
        bob.signForm(shrub);
        bob.signForm(robot);
        bob.signForm(pardon);

        alice.signForm(shrub);   // should fail

        std::cout << "\n--- Executing Forms ---\n";
        bob.executeForm(shrub);
        bob.executeForm(robot);
        bob.executeForm(pardon);

        alice.executeForm(shrub); // should fail
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
