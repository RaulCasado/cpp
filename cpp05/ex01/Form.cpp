#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Form " << _name << " created (sign: " << _gradeToSign
                << ", exec: " << _gradeToExecute << ")" << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed),
        _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << "Form assignment operator called" << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
    std::cout << "Form " << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! (minimum grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! (maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName()
        << " [" << (form.getSigned() ? "signed" : "unsigned") << "]"
        << " (required grades: sign " << form.getGradeToSign()
        << ", execute " << form.getGradeToExecute() << ")";
    return os;
}
