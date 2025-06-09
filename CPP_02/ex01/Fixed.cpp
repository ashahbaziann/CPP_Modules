#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
    std::cout << "Default constructor is called" << std::endl;
}

int Fixed::getRawBits()const{
    return this -> value;
}

void Fixed::setRawBits(int const raw){
    this -> value = raw;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor is called" << std::endl;
    this->setRawBits(other.getRawBits()); //*this = other;
}

Fixed &Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::Fixed(const int integer){
    std::cout << "Int constructor is called" << std::endl;
    this->setRawBits(integer * (1 << this->frctnl_bits));
}

Fixed::Fixed(const float floatPoint){
    std::cout << "Float constructor is called" << std::endl;
    this->setRawBits(roundf(floatPoint * (1 << this->frctnl_bits)));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const{
    return this->value / (1 << this->frctnl_bits);
}

float Fixed::toFloat(void) const{
    return float(this ->value) / (1 << this->frctnl_bits) ;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}