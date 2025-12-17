#include "Base.hpp"

Base * generate(void)
{
    int rnd = std::rand() % 3;
    switch(rnd){
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return (NULL);
}


void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}



void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(...){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(...){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(...){}
}


int main(){
    std::srand(std::time(0));
    Base *ptr1 = generate();
    identify(ptr1);
    identify(*ptr1);
    Base *ptr2 = generate();
    identify(ptr2);
    identify(*ptr2);
    Base *ptr3 = generate();
    identify(ptr3);
    identify(*ptr3);
}