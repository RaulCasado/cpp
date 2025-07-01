#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== FORM AND BUREAUCRAT TESTS ===" << std::endl << std::endl;

    // Test 1: Create valid forms
    std::cout << "--- Test 1: Create valid forms ---" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        Form permit("Building Permit", 10, 5);
        
        std::cout << taxForm << std::endl;
        std::cout << permit << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Create forms with invalid grades
    std::cout << "--- Test 2: Invalid form grades ---" << std::endl;
    try {
        Form badForm1("Bad Form 1", 0, 50); // Grade too high
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        Form badForm2("Bad Form 2", 50, 151); // Grade too low
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Successful form signing
    std::cout << "--- Test 3: Successful form signing ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form simpleForm("Simple Form", 50, 40);
        
        std::cout << "Before signing: " << simpleForm << std::endl;
        std::cout << alice << std::endl;
        
        alice.signForm(simpleForm);
        
        std::cout << "After signing: " << simpleForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Failed form signing (grade too low)
    std::cout << "--- Test 4: Failed form signing (grade too low) ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form importantForm("Important Form", 20, 10);
        
        std::cout << "Before signing attempt: " << importantForm << std::endl;
        std::cout << bob << std::endl;
        
        bob.signForm(importantForm); // Should fail
        
        std::cout << "After signing attempt: " << importantForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Multiple signing attempts
    std::cout << "--- Test 5: Multiple signing attempts ---" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 10);
        Bureaucrat dave("Dave", 1);
        Form contract("Contract", 15, 5);
        
        std::cout << "Initial form: " << contract << std::endl;
        
        charlie.signForm(contract); // Should succeed
        std::cout << "After Charlie signs: " << contract << std::endl;
        
        dave.signForm(contract); // Should succeed again (already signed)
        std::cout << "After Dave signs: " << contract << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Edge cases (grade 1 and 150)
    std::cout << "--- Test 6: Edge cases ---" << std::endl;
    try {
        Bureaucrat topBoss("Top Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form easyForm("Easy Form", 150, 150);
        Form hardForm("Hard Form", 1, 1);
        
        std::cout << "=== Easy form (grade 150 required) ===" << std::endl;
        std::cout << easyForm << std::endl;
        
        intern.signForm(easyForm);   // Should succeed
        topBoss.signForm(easyForm);  // Should also succeed
        
        std::cout << "=== Hard form (grade 1 required) ===" << std::endl;
        std::cout << hardForm << std::endl;
        
        intern.signForm(hardForm);   // Should fail
        topBoss.signForm(hardForm);  // Should succeed
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Copy constructor and assignment
    std::cout << "--- Test 7: Copy constructor and assignment ---" << std::endl;
    try {
        Form original("Original Form", 42, 21);
        std::cout << "Original: " << original << std::endl;
        
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Form assigned("Temp", 100, 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== END OF TESTS ===" << std::endl;
    return 0;
}