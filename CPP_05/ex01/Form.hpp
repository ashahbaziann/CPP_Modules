#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
private:
    const std::string   name;
    bool  isSigned;
    const int toSign;
    const int toExecute;
public:
    Form();
    ~Form();
    Form(const Form&);
    Form(const std::string& name, bool isSigned, const int toSign, const int toExecute);
    const Form &operator=(const Form& other);
public:
    const std::string getName() const ;
    bool getIsSigned();
    int getToExecute();
    int getToSign();
    void beSigned(Bureaucrat&);
    void validateGrade(int);
    class GradeTooHighException:public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException:public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& e);

#endif