#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n): _size(n){
    arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other){
    this->_size = other._size;
    this->arr = new T[other._size];
    for(unsigned i = 0; i < this->_size; ++i)
        arr[i] = other.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
    if (*this != other){
        delete[] this->arr;
        this->_size = other._size;
        this->arr = new T[other._size];
        for(unsigned i = 0; i < this->_size; ++i)
            arr[i] = other.arr[i];
    }
    return(*this);
}

template <typename T>
Array<T>::~Array(){
    if (this->arr)
        delete[] this->arr;
}

template <typename T>
unsigned int Array<T>::size()const{
    return this->_size;
}

template <typename T>
T& Array<T>::operator[](const unsigned int i) const{
    if(i >= this->_size)
       throw std::invalid_argument( "Index is out of range!" );
    return this->arr[i];
}

#endif