#include "Span.hpp"

Span::Span() : N(5) {}

Span::Span(const unsigned int n) : N(n) {}

Span::Span(const Span& other) : N(other.N), v(other.v) {}

Span& Span::operator=(const Span& rhs)
{
    if (&rhs != this)
    {
        this->N = rhs.N;
        this->v = rhs.v;
    }
    return (*this);
}

Span::~Span() {}


void Span::addNumber(int n){
    if (this->v.size() >= N)
        throw std::length_error("Length is out of range");
    v.push_back(n);
}

int Span::longestSpan() const{
    if (v.size() < 2)
        throw std::logic_error("Span requires at least two elements");
    return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()));
}

int Span::shortestSpan() const{
    if (v.size() < 2)
        throw std::logic_error("Span requires at least two elements");
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    int tmp = 0;
    int min = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); ++i){
        tmp = sorted[i] - sorted[i-1];
        if (min > tmp)
            min = tmp;
    }
    return min;
}


void Span::fill(){
    while (v.size() < N)
        v.push_back(std::rand());
}