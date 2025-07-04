#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

static int get_index(std::string &level)
{
    std::string comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if (level == comments[i])
            return (i);
    }
    return (-1);
}

void Harl::complain(std::string level){
    void (Harl::*ptrToComments[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = get_index(level);

    switch(i)
    {
        case 0:
            (this->*ptrToComments[0])();
        case 1:
            (this->*ptrToComments[1])();
        case 2:
            (this->*ptrToComments[2])();    
        case 3:
            (this->*ptrToComments[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    };
}