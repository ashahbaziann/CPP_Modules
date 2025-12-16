#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class  RobotomyRequestForm : public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm( std::string&);
    RobotomyRequestForm(const RobotomyRequestForm&);
    const RobotomyRequestForm &operator=(const RobotomyRequestForm&);
public:
    void execute(Bureaucrat const &) const;
};
#endif