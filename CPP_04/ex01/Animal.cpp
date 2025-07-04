#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal default constructor is called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destructor is called" << std::endl;
}

Animal::Animal(const Animal& other){
    std::cout << "Animal Copy constructor is called" << std::endl;
    type = other.type;
}

Animal &Animal::operator=(const Animal& other){
    std::cout << "Animal Copy assignment is called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string Animal::getType() const{
    return (this->type);
}

void Animal::makeSound() const{
    std::cout << "Animal sound!" << std::endl;
};