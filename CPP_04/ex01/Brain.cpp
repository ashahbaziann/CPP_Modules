#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor is called" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain destructor is called" << std::endl;
}

Brain::Brain(const Brain& other){
    std::cout << "Brain Copy constructor is called" << std::endl;
    for(int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain& other){
    std::cout << "Brain Copy assignment is called" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

std::string Brain::getIdea(int i) const{
    return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string& idea){
    this->ideas[i] = idea;    
}