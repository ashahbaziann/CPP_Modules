#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default"){
    std::cout << "DiamondTrap Default constructor is called" << std::endl;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){
    std::cout << "DiamondTrap parametric constructor is called" << std::endl;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name){
    std::cout << "DiamondTrap Copy constructor is called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other){
    std::cout << "DiamondTrap Copy assignment is called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    this->name = other.name;
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap "<< name << " Destructor is called" << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap "<< name << ", ClapTrap " << ClapTrap::name << std::endl;
}