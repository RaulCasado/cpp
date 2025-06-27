#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Testing ClapTrap Class ===" << std::endl;
    
    // Test constructors
    std::cout << "\n--- Constructor Tests ---" << std::endl;
    ClapTrap clap1;
    ClapTrap clap2("Warrior");
    ClapTrap clap3(clap2);
    
    // Test assignment operator
    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    ClapTrap clap4("Mage");
    clap4 = clap2;
    
    // Test attack function
    std::cout << "\n--- Attack Tests ---" << std::endl;
    clap2.attack("Enemy1");
    clap2.attack("Enemy2");
    clap2.attack("Enemy3");
    
    // Test takeDamage function
    std::cout << "\n--- Damage Tests ---" << std::endl;
    clap2.takeDamage(3);
    clap2.takeDamage(5);
    clap2.takeDamage(15); // Should destroy it
    
    // Test beRepaired function
    std::cout << "\n--- Repair Tests ---" << std::endl;
    ClapTrap clap5("Healer");
    clap5.beRepaired(5);
    clap5.beRepaired(3);
    
    // Test energy depletion
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    ClapTrap clap6("Tired");
    for (int i = 0; i < 12; i++) {
        std::cout << "Action " << i + 1 << ": ";
        if (i % 2 == 0)
            clap6.attack("Target");
        else
            clap6.beRepaired(1);
    }
    
    // Test with destroyed ClapTrap
    std::cout << "\n--- Destroyed ClapTrap Test ---" << std::endl;
    ClapTrap clap7("Destroyed");
    clap7.takeDamage(15); // Destroy it
    clap7.attack("Target"); // Should fail
    clap7.beRepaired(5); // Should fail
    
    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}