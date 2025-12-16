#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal **animals = new Animal *[4];
    for(int i = 0;i < 2; i++)
        animals[i] = new Dog;
    for(int i = 2;i < 4; i++)
        animals[i] = new Cat;
    for(int i = 0;i < 4; i++)
        animals[i]->makeSound();                     
    for(int i = 0;i < 4; i++)
        delete animals[i];
    delete[] animals;
    return 0;
}