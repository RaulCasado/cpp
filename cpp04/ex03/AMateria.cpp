#include "AMateria.hpp"

AMateria::AMateria() : type("unknown") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}