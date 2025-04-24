#include "PhoneBook.hpp"

int main()
{
    PhoneBook   p;
    std::string input;

    while(1)
    {
        std::cout << "Enter the command." << std::endl;
        getline(std::cin, input);
        if (input == "add")
        {
            p.addContact();
            input.clear();
        }
        else if (input == "search")
        {
            p.displayContacts();
            int index;
            do
            {
                std::cout << "Enter the index of the contact: ";
                std::cin >> index;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid input, try again." << std::endl;
                    continue;
                }
                if (index <= 7 && index >= 0)
                    break ;
                std::cout << "Index is out of range, try again" << std::endl;
            }
            while (true);
            p.searchContact(index);
            std::cin.clear();
			std::getline(std::cin, input);
			continue;
        }
        else if (input == "exit")
            break;
        else
            input.clear();
    }
}