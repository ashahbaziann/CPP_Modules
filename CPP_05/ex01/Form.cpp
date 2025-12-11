#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), toSign(1), toExecute(1){
    std::cout << "Form default constructor called" << std::endl;
};

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const std::string& name, bool isSigned, const int toSign, const int toExecute): name(name), isSigned(isSigned), toSign(toSign), toExecute(toExecute){
    std::cout << "Form non-default constructor called" << std::endl;
    this->validateGrade(toSign);
    this->validateGrade(toExecute);

};

Form::Form(const Form& oth): name(oth.name), isSigned(oth.isSigned), toSign(oth.toSign), toExecute(oth.toExecute){
    std::cout << "Form Copy ctr is called" << std::endl;
}
const Form& Form::operator=(const Form& other){
    std::cout << "Form Copy assignment is called" << std::endl;
    if (this != &other)
    {
        std::string* hack = const_cast<std::string*>(&name);
        *hack = other.name;   
        this->isSigned = other.isSigned;
        // this->toSign = other.toSign;
        // this->toExecute = other.toExecute;
    }
    return(*this);
}

const std::string Form::getName() const {
    return name;
}
bool Form::getIsSigned(){
    return isSigned;
}
int Form::getToSign(){
    return toSign;
}
int Form::getToExecute(){
    return toExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->toSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void Form::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& e){
    out << e.getName() << ", bureaucrat grade "  << std::endl;
    return out;
}

const char *Form::GradeTooHighException::what() const throw(){
    return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw(){
    return ("Grade is too low!");
}