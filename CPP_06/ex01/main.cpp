#include "Serializer.hpp"

int main(){
    Data tmp;
    tmp.i = 7;
    Data *ptr = &tmp;
    std::cout << "ptr : " << ptr << std::endl;
    try{
        uintptr_t raw = Serializer::serialize(ptr);
        std::cout << "raw : " << raw << std::endl;
    
        Data* new_ptr = Serializer::deserialize(raw);
        std::cout << "new_ptr : " << new_ptr << std::endl;
    }
    catch(std::exception &e){
        std::cerr << "Exception :" << e.what() << std::endl; 
        return (1);
    }
    return (0);
}