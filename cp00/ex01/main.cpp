#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string &prompt) {
    std::string input;
    while (input.empty()) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Field cannot be empty. Please try again." << std::endl;
        }
    }
    return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to the Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            std::string firstName = getInput("Enter first name: ");
            std::string lastName = getInput("Enter last name: ");
            std::string nickname = getInput("Enter nickname: ");
            std::string phoneNumber = getInput("Enter phone number: ");
            std::string darkestSecret = getInput("Enter darkest secret: ");
            
            Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH") {
            phoneBook.searchContacts();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    
    return 0;
}