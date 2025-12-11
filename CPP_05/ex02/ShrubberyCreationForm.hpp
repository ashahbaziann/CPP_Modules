#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#define tree                            \
	"          	  &&&& \n"              \
	"          &&& &&  & &&\n"          \
	"      && &\\/&\\|& ()|/ @, &&\n"   \
	"      &\\/(/&/&||/& /_/)_&/_&\n"   \
	"   &() &\\/&|()|/&\\/ '%\" & ()\n" \
	"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n" \
	"&&   && & &| &| /& & % ()& /&&\n"  \
	" ()&_---()&\\&\\|&&-&&--%---()~\n" \
	"     &&     \\|||\n"               \
	"             |||\n"                \
	"             |||\n"                \
	"             |||\n"                \
    
class  ShrubberyCreationForm : public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(std::string&);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    const ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
public:
    void execute(Bureaucrat const &) const;
};
#endif