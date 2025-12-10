#include "Bureaucrat.hpp"

int main(){
     try
    {
        Bureaucrat bob("Bob", 50);
        Form formA("FormA",0,  30, 20);  // requires grade 30 to sign

        std::cout << "Trying to sign with Bob (grade 50)..." << std::endl;
        bob.signForm(formA);  // should fail

        Bureaucrat alice("Alice", 20);
        std::cout << "Trying to sign with Alice (grade 20)..." << std::endl;
        alice.signForm(formA);  // should succeed

        std::cout << "Form signed status: " << formA.getIsSigned() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}