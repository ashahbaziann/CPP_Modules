#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog default constructor is called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::~Dog(){
    std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog(const Dog& other){
    std::cout << "Dog Copy constructor is called" << std::endl;
    type = other.type;
}

Dog &Dog::operator=(const Dog& other){
    std::cout << "Dog Copy assignment is called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Woof!" << std::endl;
};

void Dog::setIdea(int i, std::string& idea) {
    std::cout << "idea: " << idea << std::endl;
    brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const {
    return brain->getIdea(i);
}
