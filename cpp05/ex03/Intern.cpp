#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created (ready to make forms)" << std::endl;
}

Intern::Intern(const Intern& other) {
    *this = other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destroyed (no more forms)" << std::endl;
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    AForm* (Intern::*creators[])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    
    std::cout << "Error: Form '" << formName << "' does not exist!" << std::endl;
    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form type requested!";
}