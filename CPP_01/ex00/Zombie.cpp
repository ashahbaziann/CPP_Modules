#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this -> name = name;
    std::cout << getName() << " was created." << std::endl;
}

void Zombie::announce(){
    std::cout << getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << getName() << " died." << std::endl;
}

void Zombie::setName(std::string name){
    this -> name = name;
}

std::string Zombie::getName(void){
    return this->name;
}