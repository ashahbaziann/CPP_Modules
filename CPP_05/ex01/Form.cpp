#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), toSign(1), toExecute(1){};

Form::~Form(){}

Form::Form(const std::string& name, bool isSigned, const int toSign, const int toExecute): name(name), isSigned(isSigned), toSign(toSign), toExecute(toExecute){};

const Form& Form::operator=(const Form& other){
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