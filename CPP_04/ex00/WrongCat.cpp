#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "WrongCat default constructor is called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other){
    std::cout << "WrongCat Copy constructor is called" << std::endl;
    type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat& other){
    std::cout << "WrongCat Copy assignment is called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Meow!" << std::endl;
};