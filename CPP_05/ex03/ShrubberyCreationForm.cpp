#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():  AForm("ShrubberyDef", 0, 145, 137) ,target("default"){
    std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target): AForm("ShrubberyDef", 0, 145, 137) ,target(target){
    std::cout << "Shrubbery parametric constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Shrubbery deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& oth): AForm("ShrubberyDef", 0, 145, 137) ,target(oth.target){
    std::cout << "Shrubbery copy constructor called" << std::endl;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& oth){
    std::cout << "Shrubbery copy assign called" << std::endl;
    if (this != &oth)
    {
        AForm::operator=(oth);
        this->target = oth.target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    AForm::executeForm(executor);
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (outfile.is_open())
	{
		outfile << tree;
		outfile.close();
	}
}