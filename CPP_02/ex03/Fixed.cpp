#include "Fixed.hpp"

Fixed::Fixed(): value(0) {}

int Fixed::getRawBits()const{
    return this -> value;
}

void Fixed::setRawBits(int const raw){
    this -> value = raw;
}

Fixed::Fixed(const Fixed& other){
    this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed& other){
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::Fixed(const int integer){
    this->setRawBits(integer * (1 << this->frctnlBits));
}

Fixed::Fixed(const float floatPoint){
    this->setRawBits(roundf(floatPoint * (1 << this->frctnlBits)));
}

Fixed::~Fixed(){}

int Fixed::toInt(void) const{
    return this->value / (1 << this->frctnlBits);
}

float Fixed::toFloat(void) const{
    return float(this ->value) / (1 << this->frctnlBits) ;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& other) const{
    if (this->value > other.value)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other) const{
    if (this->value >= other.value)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other) const{
    if (this->value < other.value)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const{
    if (this->value <= other.value)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other) const{
    if (this->value == other.value)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const{
    if (this->value != other.value)
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed& other){
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other){ 
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other){ 
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other){ 
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(){
    this->value++;
    return (*this);
}

Fixed &Fixed::operator--(){
    this->value--;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed tmp;
    tmp = *this;
    this->value++;
    return (tmp);
}

Fixed Fixed::operator--(int){
    Fixed tmp;
    tmp = *this;
    this->value--;
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a > b)
        return b;
    return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a < b)
        return b;
    return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a > b)
        return b;
    return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a < b)
        return b;
    return a;
}