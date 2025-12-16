#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm{
private:
    const std::string   name;
    bool  isSigned;
    const int toSign;
    const int toExecute;
public:
    AForm();
    virtual ~AForm();
    AForm(const AForm&);
    AForm(const std::string& name, bool isSigned, const int toSign, const int toExecute);
    const AForm &operator=(const AForm& other);
public:
    const std::string getName() const ;
    bool getIsSigned();
    int getToExecute();
    int getToSign();
    void beSigned(Bureaucrat&);
    void validateGrade(int);
    void executeForm(const Bureaucrat&) const;
    class GradeTooHighException:public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException:public std::exception{
        public:
            const char* what() const throw();
    };
    class IsSignedException:public std::exception{
        public:
            const char* what() const throw();
    };

protected:
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& e);

#endif