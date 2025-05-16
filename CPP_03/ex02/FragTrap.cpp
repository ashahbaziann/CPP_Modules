#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default"){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Init name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
    std::cout << "FragTrap Copy constructor is called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other){
    if (this != &other)
    {
        std::cout << "FragTrap Copy assignment is called" << std::endl;
        this->set_name(other.name);
        this->set_hitPoints(other.hitPoints);
        this->set_energyPoints(other.energyPoints);
        this->set_attackDamage(other.attackDamage);
    }
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap "<< name << " Destructor is called" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap "<< name << " gives a high-five" << std::endl;
}