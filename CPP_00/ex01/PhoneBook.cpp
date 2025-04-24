#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    currentIndex = 0;
    contactCount = 0;
}
static int      is_valid_number(std::string number)
{
        int     i;

        i = 0;
        while (number[i])
        {
                if (number[i] == ' ')
                {
                        i++;
                        continue;
                }
                if (!std::isdigit(number[i]))
                        return (0);
                i++;
        }
        return (1);
}

void PhoneBook::addContact()
{
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, input);
    contacts[currentIndex].setFirstName(input);

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    contacts[currentIndex].setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    contacts[currentIndex].setNickName(input);

    do
    {
        std::cout << "Phone Number: ";
        std::getline(std::cin, input);
        if (is_valid_number(input))
            break;
        std::cout << "Please input a valid number" << std::endl;
    } while (!is_valid_number(input));
    contacts[currentIndex].setPhoneNumber(input);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    contacts[currentIndex].setDarkestSecret(input);

    currentIndex = (currentIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
}


Contact PhoneBook::getFirstName(int index){
    return contacts[index];
}
Contact PhoneBook::getLastName(int index){
    return contacts[index];
}
Contact PhoneBook::getNickName(int index){
    return contacts[index];
}
Contact PhoneBook::getPhoneNumber(int index){
    return contacts[index];
}
Contact PhoneBook::getDarkestSecret(int index){
    return contacts[index];
}

void PhoneBook::searchContact(int index)
{
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nick name: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string formatField(const std::string &src) {
    std::string res = src;
	if (res.length() > 10)
		res.replace(res.begin() + 9, res.end(), ".");
	if (res.length() == 10)
		return res;
	res.append(10 - res.length(), ' ');
	return res;
}

void PhoneBook::displayContacts()
{
	int i = 0;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (i < contactCount)
	{
		std::cout << "|         " << i;
		std::cout << "|";
		std::cout << formatField(contacts[i].getFirstName());
		std::cout << "|";
		std::cout << formatField(contacts[i].getLastName());
		std::cout << "|";
		std::cout << formatField(contacts[i].getNickName());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

