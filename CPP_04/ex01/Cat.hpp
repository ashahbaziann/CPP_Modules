#include "Animal.hpp"

class Cat:public Animal{
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat &operator=(const Cat& other);
    ~Cat();

    void makeSound() const;

};