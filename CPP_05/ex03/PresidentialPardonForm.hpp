#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class  PresidentialPardonForm : public AForm {
private:
    std::string target;
public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(std::string&);
    PresidentialPardonForm(const PresidentialPardonForm&);
    const PresidentialPardonForm &operator=(const PresidentialPardonForm&);
public:
    void execute(Bureaucrat const &) const;
};
#endif