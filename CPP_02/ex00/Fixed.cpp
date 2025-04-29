#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

int Fixed::getRawBits()const{
    return this -> value;
}

void Fixed::setRawBits(int const raw){
    this -> value = raw;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}


Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
