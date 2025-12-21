#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Span{
public:
    Span();
    Span(const unsigned int);
    Span(const Span&);
    Span& operator=(const Span&);
    ~Span();

    void addNumber(int);
    int shortestSpan() const;
    int longestSpan() const;
    void fill();
public:
    unsigned int N;
    std::vector<int> v;
};
#endif