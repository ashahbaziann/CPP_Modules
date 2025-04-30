#include "Point.hpp"

Point::Point(): x(0), y(0){}

Point::~Point(){}

Point::Point(const float x, const float y): x(x), y(y){}

const Fixed &Point::getX(void) const{
    return (this->x);
}

const Fixed &Point::getY(void) const{
    return (this->y);
}

Point::Point(const Point& other): x(other.getX()), y(other.getY()){}

Point &Point::operator=(const Point& other){
    (void)other;
    return (*this);
}