#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "=== INTERN FACTORY TEST ===" << std::endl << std::endl;

    // Test 1: Create intern
    std::cout << "--- Test 1: Create intern ---" << std::endl;
    Intern someRandomIntern;
    std::cout << std::endl;

    // Test 2: Valid form creation
    std::cout << "--- Test 2: Valid form creation ---" << std::endl;
    try {
        AForm* forms[3];
        
        forms[0] = someRandomIntern.makeForm("shrubbery creation", "garden");
        forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
        forms[2] = someRandomIntern.makeForm("presidential pardon", "Arthur");
        
        for (int i = 0; i < 3; i++) {
            std::cout << *forms[i] << std::endl;
            delete forms[i];
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Invalid form name
    std::cout << "--- Test 3: Invalid form name ---" << std::endl;
    try {
        AForm* badForm = someRandomIntern.makeForm("invalid form", "target");
        delete badForm; // Won't reach here
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Full workflow with intern-created forms
    std::cout << "--- Test 4: Full workflow ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        AForm* form = someRandomIntern.makeForm("robotomy request", "employee");
        
        std::cout << "Form created: " << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        
        delete form;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Multiple interns
    std::cout << "--- Test 5: Multiple interns ---" << std::endl;
    try {
        Intern intern1;
        Intern intern2;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "office");
        AForm* form2 = intern2.makeForm("presidential pardon", "criminal");
        
        std::cout << "Intern 1 created: " << *form1 << std::endl;
        std::cout << "Intern 2 created: " << *form2 << std::endl;
        
        delete form1;
        delete form2;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Copy constructor and assignment
    std::cout << "--- Test 6: Copy and assignment ---" << std::endl;
    try {
        Intern original;
        Intern copy(original);
        Intern assigned;
        assigned = original;
        
        AForm* form1 = copy.makeForm("robotomy request", "target1");
        AForm* form2 = assigned.makeForm("shrubbery creation", "target2");
        
        delete form1;
        delete form2;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== INTERN TESTS COMPLETED ===" << std::endl;
    return 0;
}