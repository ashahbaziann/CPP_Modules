#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog default constructor is called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::~Dog(){
    std::cout << "Dog destructor is called" << std::endl;
    delete (this->brain);
}

Dog::Dog(const Dog& other) : Animal(other){
    std::cout << "Dog Copy constructor is called" << std::endl;
    type = other.type;
    if (this->brain)
            delete this->brain;
    this->brain = new Brain;
    *(this->brain) = *(other.brain);
}

Dog &Dog::operator=(const Dog& other){
    std::cout << "Dog Copy assignment is called" << std::endl;
    if (this != &other)
    {
        if (this->brain)
            delete this->brain;
        this->brain = new Brain;
        *(this->brain) = *(other.brain);
        this->type = other.type;
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Woof!" << std::endl;
};
