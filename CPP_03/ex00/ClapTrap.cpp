#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name),hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap parametric constructor is called called" << std::endl;
}

std::string const ClapTrap::getName() const{
    return this->name;
}

void ClapTrap::set_name(const std::string name){
    this->name = name;
}

int ClapTrap::get_hitPoints() const{
    return this->hitPoints;
}

void ClapTrap::set_hitPoints(int hitPoints){
    this->hitPoints = hitPoints;
}

int ClapTrap::get_energyPoints() const{
    return this->energyPoints;
}

void ClapTrap::set_energyPoints(int energyPoints){
    this->energyPoints = energyPoints;
}

int ClapTrap::get_attackDamage() const{
    return this->attackDamage;
}

void ClapTrap::set_attackDamage(int attackDamage){
    this->attackDamage = attackDamage;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
    std::cout << "Copy constructor is called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other){
    std::cout << "Copy assignment is called" << std::endl;
    if (this != &other)
    {
        this->set_name(other.name);
        this->set_hitPoints(other.hitPoints);
        this->set_energyPoints(other.energyPoints);
        this->set_attackDamage(other.attackDamage);
    }
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor is called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->energyPoints && this->hitPoints)
    {
        std::cout << "ClapTrap " << this->getName() << " attacks " << target <<", causing "<< this->attackDamage << " points of damage!" << std::endl;
        this->set_energyPoints(this->energyPoints - 1);
    }
    else
        std::cout << "ClapTrap has no energy or hit points left" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount){
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    if (this->hitPoints <= (int)amount)
        this->set_hitPoints(0);
    else
        this->set_hitPoints(this->hitPoints - amount);
    std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage! "
        << "Current hitPoints: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->energyPoints && this->hitPoints)
    {
        this->set_hitPoints(this->hitPoints + amount);
        std::cout << "ClapTrap " << this->getName() << " repairs for " << amount << " hit points!" 
        << " Current hitPoints: " << this->hitPoints << std::endl;
        this->set_energyPoints(this->energyPoints - 1);
    }
    else
        std::cout << "ClapTrap " << this->getName() << " has no energy to repair!" << std::endl;
}