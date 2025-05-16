#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default"){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Init name constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
    std::cout << "ScavTrap Copy constructor is called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other){
    if (this != &other)
    {
        std::cout << "ScavTrap Copy assignment is called" << std::endl;
        this->set_name(other.name);
        this->set_hitPoints(other.hitPoints);
        this->set_energyPoints(other.energyPoints);
        this->set_attackDamage(other.attackDamage);
    }
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap "<< name << " Destructor is called" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap "<< name << " is now in the Gate keeper mode" << std::endl;
}