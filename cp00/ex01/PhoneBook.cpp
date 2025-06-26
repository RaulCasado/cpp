#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), currentIndex(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact) {
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % 8;
    if (contactCount < 8) {
        contactCount++;
    }
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0){
        std::cout << "No contacts available." << std::endl;
        return;
    }

    displayContactList();
    std::cout << "Enter the index of the contact to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "No input provided." << std::endl;
        return;
    }
    if (input.length() != 1 || (input[0] < '0' && input[0] > '7')) {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    int index = input[0] - '0';
    if (index < 0 || index >= contactCount) {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    displayContactDetails(index);
}


void PhoneBook::displayContactList() const {
    std::cout << std::setw(10) << std::right << "Index" << "|"
                << std::setw(10) << std::right << "First Name" << "|"
                << std::setw(10) << std::right << "Last Name" << "|"
                << std::setw(10) << std::right << "Nickname" << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << std::right << i << "|";
        
        std::string firstName = contacts[i].getFirstName();
        if (firstName.length() > 10) {
            firstName = firstName.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << firstName << "|";
        
        std::string lastName = contacts[i].getLastName();
        if (lastName.length() > 10) {
            lastName = lastName.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << lastName << "|";
        
        std::string nickname = contacts[i].getNickname();
        if (nickname.length() > 10) {
            nickname = nickname.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << nickname << std::endl;
    }
}


void PhoneBook::displayContactDetails(int index) const {
    if (index >= 0 && index < contactCount) {
        contacts[index].displayContact();
    }
}