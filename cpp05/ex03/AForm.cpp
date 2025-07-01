#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
    std::cout << "AForm " << _name << " created (sign: " << _gradeToSign 
              << ", exec: " << _gradeToExecute << ")" << std::endl;
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << "AForm assignment operator called" << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm " << _name << " destroyed" << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
    std::cout << "AForm " << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high! (minimum grade is 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low! (maximum grade is 150)";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm " << form.getName() 
       << " [" << (form.getSigned() ? "signed" : "unsigned") << "]"
       << " (required grades: sign " << form.getGradeToSign() 
       << ", execute " << form.getGradeToExecute() << ")";
    return os;
}
