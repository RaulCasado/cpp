#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int currentIndex;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact &contact);
    void searchContacts() const;
    void displayContactList() const;
    void displayContactDetails(int index) const;
    int getContactCount() const;
    int getCurrentIndex() const;
    void setCurrentIndex(int index);
    Contact getContact(int index) const;
    void setContact(int index, const Contact &contact);
};

#endif