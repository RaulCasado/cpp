#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== BUREAUCRAT TESTS ===" << std::endl << std::endl;

    std::cout << "--- Test 1: Valid constructor ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 2: Grade too high (0) ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: Grade too low (151) ---" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 4: Increment grade ---" << std::endl;
    try {
        Bureaucrat dave("Dave", 50);
        std::cout << "Before: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 5: Decrement grade ---" << std::endl;
    try {
        Bureaucrat eve("Eve", 100);
        std::cout << "Before: " << eve << std::endl;
        eve.decrementGrade();
        std::cout << "After decrement: " << eve << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 6: Increment grade 1 (should throw) ---" << std::endl;
    try {
        Bureaucrat frank("Frank", 1);
        std::cout << "Before: " << frank << std::endl;
        frank.incrementGrade();
        std::cout << "After increment: " << frank << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 7: Decrement grade 150 (should throw) ---" << std::endl;
    try {
        Bureaucrat grace("Grace", 150);
        std::cout << "Before: " << grace << std::endl;
        grace.decrementGrade();
        std::cout << "After decrement: " << grace << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 8: Copy constructor and assignment ---" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        std::cout << "Original: " << original << std::endl;

        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;

        Bureaucrat assigned("Temp", 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== END OF TESTS ===" << std::endl;
    return 0;
}
