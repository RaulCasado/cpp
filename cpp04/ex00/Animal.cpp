#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
    std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assignment operator called" << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}