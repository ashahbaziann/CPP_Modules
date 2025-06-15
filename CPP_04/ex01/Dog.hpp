#include "Animal.hpp"

class Dog:public Animal{
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog& other);
    Dog &operator=(const Dog& other);
    ~Dog();

    void makeSound() const;
    std::string getIdea(int) const;
    void setIdea(int, std::string&);
};