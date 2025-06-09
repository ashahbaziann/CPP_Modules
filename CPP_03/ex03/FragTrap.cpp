#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default FragTrap"){
    std::cout << "FragTrap Default constructor is called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name){
    std::cout << "FragTrap parametric constructor is called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
    std::cout << "FragTrap Copy constructor is called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other){
    std::cout << "FragTrap Copy assignment is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap "<< name << " Destructor is called" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap "<< name << " gives a high-five" << std::endl;
}