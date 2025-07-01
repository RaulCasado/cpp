#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm for target " << _target << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "🎉 " << _target << " has been pardoned by Zaphod Beeblebrox! 🎉" << std::endl;
}