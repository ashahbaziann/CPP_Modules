#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    const Bureaucrat &operator=(const Bureaucrat& other);
public:
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade(); 
    class GradeTooHighException:public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException:public std::exception{
        public:
            const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif