#include "Bureaucrat.hpp"

int main(){
    try {
        Bureaucrat b("John", 140);
        std::cout << b;
        Bureaucrat c;
        c = b;
        std::cout << c;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat a("Alice", 150);
        std::cout << a;
        a.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}