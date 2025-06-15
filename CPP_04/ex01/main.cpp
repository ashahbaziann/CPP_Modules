#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animals[4];
    for(int i = 0;i < 2; i++)
        animals[i] = new Dog;
    for(int i = 2;i < 4; i++)
        animals[i] = new Cat;
    for(int i = 0;i < 4; i++)
        animals[i]->makeSound();                     
    for(int i = 0;i < 4; i++)
        delete animals[i];
    Dog d;
    std::string k = "hello";
    d.setIdea(0,k);
    return 0;
}