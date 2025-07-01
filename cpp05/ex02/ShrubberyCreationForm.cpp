#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm for target " << _target << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cout << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file << std::endl;
    file << "      _\\/_" << std::endl;
    file << "     /     \\" << std::endl;
    file << "    |       |" << std::endl;
    file << "    |_______|" << std::endl;
    
    file.close();
    std::cout << "🌲 Shrubbery planted at " << _target << "! File: " << filename << std::endl;
}