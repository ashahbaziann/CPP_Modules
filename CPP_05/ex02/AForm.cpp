#include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), toSign(1), toExecute(1){
    std::cout << "AForm default constructor called" << std::endl;
};

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string& name, bool isSigned, const int toSign, const int toExecute): name(name), isSigned(isSigned), toSign(toSign), toExecute(toExecute){
    std::cout << "AForm non-default constructor called" << std::endl;
    this->validateGrade(toSign);
    this->validateGrade(toExecute);

};

AForm::AForm(const AForm& oth): name(oth.name), isSigned(oth.isSigned), toSign(oth.toSign), toExecute(oth.toExecute){
    std::cout << "AForm Copy ctr is called" << std::endl;
}
const AForm& AForm::operator=(const AForm& other){
    std::cout << "AForm Copy assignment is called" << std::endl;
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

const std::string AForm::getName() const {
    return name;
}
bool AForm::getIsSigned(){
    return isSigned;
}
int AForm::getToSign(){
    return toSign;
}
int AForm::getToExecute(){
    return toExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->toSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::executeForm(const Bureaucrat& executor) const{
    if(!isSigned)
        throw IsSignedException();
    else if(executor.getGrade() > this->toExecute)
        throw GradeTooLowException();
}

void AForm::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& e){
    out << e.getName() << ", bureaucrat grade "  << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw(){
    return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw(){
    return ("Grade is too low!");
}

const char *AForm::IsSignedException::what() const throw(){
    return("Form isn't signed!");
}