#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    class UnknownFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    AForm* createShrubbery(const std::string& target);
    AForm* createRobotomy(const std::string& target);
    AForm* createPresidential(const std::string& target);
};

#endif