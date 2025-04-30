#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    ~Point();
    Point(const Point& other);
    Point &operator=(const Point& other);
    Point(const float x,const float y);
    const Fixed& getX(void) const;
    const Fixed& getY(void) const;    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif