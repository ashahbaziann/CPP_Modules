#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
    int value;
    static const int frctnlBits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed& other);
    Fixed(const int integer);
    Fixed(const float floatPoint); 
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif
