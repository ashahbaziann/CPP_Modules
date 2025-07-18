#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void){
    std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
    std::string comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptrToComments[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for(int i = 0; i < 4; i++)
    {
        if (level == comments[i])
        {
            (this->*ptrToComments[i])();           
            return ;
        }
    }
    std::cout << "Invalid arguments!" << std::endl;
    return ;
}