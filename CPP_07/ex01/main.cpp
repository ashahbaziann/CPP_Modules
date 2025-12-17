#include "iter.hpp"


void printInt(const int& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    x++;
}

void printString(const std::string& s) {
    std::cout << s << " ";
}

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    size_t lenInt = sizeof(arrInt)/sizeof(arrInt[0]);

    std::cout << "Original int array: ";
    iter(arrInt, lenInt, printInt);
    std::cout << std::endl;

    iter(arrInt, lenInt, increment);

    std::cout << "After increment: ";
    iter(arrInt, lenInt, printInt);
    std::cout << std::endl;

    std::string arrStr[] = {"hello", "world", "iter"};
    size_t lenStr = sizeof(arrStr)/sizeof(arrStr[0]);

    std::cout << "String array: ";
    iter(arrStr, lenStr, printString);
    std::cout << std::endl;

    return 0;
}