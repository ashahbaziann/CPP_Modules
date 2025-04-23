#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     contactCount;
    int     currentIndex;
public:
    PhoneBook();
    void addContact();
    void searchContact(int index);
    void displayContacts();
private:
    Contact getFirstName(int index);
    Contact getLastName(int index);
    Contact getNickName(int index);
    Contact getPhoneNumber(int index);
    Contact getDarkestSecret(int index);

};

#endif