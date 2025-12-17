#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cmath>
template <class T>
class Array{
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array&);
    ~Array();
public:
    unsigned int size() const;
    T &operator[](const unsigned int i) const;
private:
    T* arr;
    unsigned int _size;
};

#include "Array.tpp"

#endif