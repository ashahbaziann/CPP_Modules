#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor is called" << std::endl;
}

Intern::~Intern(){
    std::cout << "Intern dconstructor is called" << std::endl;
}

Intern::Intern(const Intern &other){
    std::cout << "Intern copy constructor is called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other){
    std::cout << "Intern copy assignment operator is called" << std::endl;
    if (this == &other)
        return(*this);
    *this = other;
    return(*this);
}

AForm* Intern::makeForm(std::string name, std::string target){
    std::string forms[3] =  {"presidential pardon","robotomy request","shrubberycreation"};
    int i = 0;
    while (i < 3 && forms[i] != name)
        i++;
    if (i < 3)
        std::cout << "Intern creates " << name << std::endl;
    else
        std::cout << "There is no form named " << name << std::endl;
    switch (i)
    {
        case(0):
            return(new PresidentialPardonForm(target));
        case(1):
            return(new RobotomyRequestForm(target));
        case(2):
            return(new ShrubberyCreationForm(target));
    }
    return (NULL);
}