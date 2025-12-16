#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat default constructor is called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat destructor is called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat Copy constructor is called" << std::endl;
    type = other.type;
}

Cat &Cat::operator=(const Cat& other){
    std::cout << "Cat Copy assignment is called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meow!" << std::endl;
};