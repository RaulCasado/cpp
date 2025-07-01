#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== BUREAUCRACY SIMULATOR 2024 ===" << std::endl << std::endl;

    // Test 1: Create concrete forms
    std::cout << "--- Test 1: Creating concrete forms ---" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("victim");
        PresidentialPardonForm pardon("criminal");
        
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Execute unsigned forms (should fail)
    std::cout << "--- Test 2: Execute unsigned forms ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("park");
        
        std::cout << boss << std::endl;
        std::cout << shrub << std::endl;
        
        boss.executeForm(shrub); // Should fail - not signed
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Full workflow - Sign and Execute
    std::cout << "--- Test 3: Sign and Execute ShrubberyCreationForm ---" << std::endl;
    try {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << "Before signing: " << shrub << std::endl;
        gardener.signForm(shrub);
        std::cout << "After signing: " << shrub << std::endl;
        
        gardener.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: RobotomyRequestForm (50% chance)
    std::cout << "--- Test 4: RobotomyRequestForm ---" << std::endl;
    try {
        Bureaucrat surgeon("Dr. Robot", 40);
        RobotomyRequestForm robotomy("patient");
        
        surgeon.signForm(robotomy);
        surgeon.executeForm(robotomy);
        
        // Try again to see different result
        RobotomyRequestForm robotomy2("patient2");
        surgeon.signForm(robotomy2);
        surgeon.executeForm(robotomy2);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: PresidentialPardonForm (high grade required)
    std::cout << "--- Test 5: PresidentialPardonForm ---" << std::endl;
    try {
        Bureaucrat lowLevel("Intern", 100);
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Marvin");
        
        std::cout << "=== Low level bureaucrat tries to sign ===" << std::endl;
        lowLevel.signForm(pardon); // Should fail
        
        std::cout << "=== President signs and executes ===" << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Execute with insufficient grade
    std::cout << "--- Test 6: Execute with insufficient grade ---" << std::endl;
    try {
        Bureaucrat signer("Signer", 20);
        Bureaucrat lowExecutor("Low Executor", 50);
        PresidentialPardonForm pardon("Arthur");
        
        signer.signForm(pardon);
        lowExecutor.executeForm(pardon); // Should fail - grade too low to execute
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Polymorphism test
    std::cout << "--- Test 7: Polymorphism test ---" << std::endl;
    try {
        Bureaucrat admin("Admin", 1);
        AForm* forms[3];
        
        forms[0] = new ShrubberyCreationForm("office");
        forms[1] = new RobotomyRequestForm("intern");
        forms[2] = new PresidentialPardonForm("Zaphod");
        
        for (int i = 0; i < 3; i++) {
            std::cout << "Processing: " << *forms[i] << std::endl;
            admin.signForm(*forms[i]);
            admin.executeForm(*forms[i]);
            std::cout << std::endl;
        }
        
        // Clean up
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== END OF BUREAUCRACY ===" << std::endl;
    return 0;
}