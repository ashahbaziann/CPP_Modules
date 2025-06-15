#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat default constructor is called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain;
}

Cat::~Cat(){
    std::cout << "Cat destructor is called" << std::endl;
    delete (this->brain);
}

Cat::Cat(const Cat& other){
    std::cout << "Cat Copy constructor is called" << std::endl;
    type = other.type;
    if (this->brain)
            delete this->brain;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat& other){
    std::cout << "Cat Copy assignment is called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain;
        *(this->brain) = *(other.brain);
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meow!" << std::endl;
};
