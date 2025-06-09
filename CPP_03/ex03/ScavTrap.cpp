#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default ScavTrap"){
    std::cout << "ScavTrap Default constructor is called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name){
    std::cout << "ScavTrap parametric constructor is called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
    std::cout << "ScavTrap Copy constructor is called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other){
    std::cout << "ScavTrap Copy assignment is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap "<< name << " Destructor is called" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap "<< name << " is now in the Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target <<", causing "<< this->attackDamage << " points of damage!" << std::endl;
        this->set_energyPoints(this->energyPoints - 1);
    }
    else
        std::cout << "ScavTrap "<< name << " has no energy or hit points left to attack!" << std::endl;
}
