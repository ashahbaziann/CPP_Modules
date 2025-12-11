#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():  AForm("PresidentialDef", 0, 25, 5) ,target("default"){
    std::cout << "Presidential default ctr called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string& target): AForm("PresidentialDef", 0, 25, 5) ,target(target){
    std::cout << "Presidential prm ctr called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential dctr called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& oth): AForm("PresidentialDef", 0, 25, 5) ,target(oth.target){
    std::cout << "Presidential copy ctr called" << std::endl;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& oth){
    std::cout << "Presidential copy assign called" << std::endl;
    if (this != &oth)
        this->target = oth.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    AForm::executeForm(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}