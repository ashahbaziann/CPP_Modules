#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name,int grade): name(name), grade(grade){
    std::cout << "Bureaucrat non-default constructor called" << std::endl;
    if (this->grade < 1)
        throw GradeTooHighException();
    if (this->grade > 150)
        throw GradeTooLowException();
}


Bureaucrat::Bureaucrat(const Bureaucrat& oth): name(oth.name), grade(oth.grade){
    std::cout << "Bureaucrat Copy ctr is called" << std::endl;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    std::cout << "Bureaucrat Copy assignment is called" << std::endl;
    if (this != &other)
    {
        std::string* hack = const_cast<std::string*>(&name);
        *hack = other.name;        
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade is too low!");
}

const std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void Bureaucrat::incrementGrade(){
    grade--;
    std::cout << "Bureaucrat incremented" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::decrementGrade(){
    grade++;
    std::cout << "Bureaucrat decremented" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}



std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return out;
}
