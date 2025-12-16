#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm* f = intern.makeForm("robotomy request", "Bender");
    delete f;

    return 0;
}
