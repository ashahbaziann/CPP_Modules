#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():  AForm("RobotomyDef", 0, 72, 45) ,target("default"){
    std::cout << "Robotomy default ctr called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string& target): AForm("RobotomyDef", 0, 72, 45) ,target(target){
    std::cout << "Robotomy prm ctr called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Robotomy dctr called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& oth): AForm("RobotomyDef", 0, 72, 45) ,target(oth.target){
    std::cout << "Robotomy copy ctr called" << std::endl;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& oth){
    std::cout << "Robotomy copy assign called" << std::endl;
    if (this != &oth)
        this->target = oth.target;//smt misiing
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    AForm::executeForm(executor);
    std::cout << "Bzzzzzzzzzzz" << std::endl;
    if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
}
