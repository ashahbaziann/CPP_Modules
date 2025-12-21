#include "easyfind.hpp"

template <typename T>
void _find(T& container, int value){
    typename T::iterator it = easyfind(container, value);
    if (it != container.end())
        std::cout << *it <<  " is found"<<std::endl;
    else
        std::cout << value << " is not found" <<std::endl;
}

int main(){
    std::vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    _find(v, 7); 
    _find(v, 4); 
    
}