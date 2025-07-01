#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " with grade " << _grade << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    _grade--;
    std::cout << _name << " grade incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    _grade++;
    std::cout << _name << " grade decremented to " << _grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (minimum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
