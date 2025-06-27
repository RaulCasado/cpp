#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Testing ScavTrap Inheritance ===" << std::endl;
    
    // Test construction/destruction chaining
    std::cout << "\n--- Construction Chaining Test ---" << std::endl;
    ScavTrap scav1("Guardian");
    
    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    ScavTrap scav2(scav1);
    
    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    ScavTrap scav3("Defender");
    scav3 = scav1;
    
    // Test ScavTrap specific attack
    std::cout << "\n--- ScavTrap Attack Tests ---" << std::endl;
    scav1.attack("Enemy Robot");
    scav1.attack("Another Enemy");
    
    // Test inherited functions
    std::cout << "\n--- Inherited Functions Test ---" << std::endl;
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    
    // Test special ability
    std::cout << "\n--- Gate Keeper Mode Test ---" << std::endl;
    scav1.guardGate();
    scav2.guardGate();
    
    // Test energy depletion
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    ScavTrap scav4("Energetic");
    for (int i = 0; i < 52; i++) { // ScavTrap has 50 energy points
        if (i < 10) {
            scav4.attack("Target");
        } else if (i == 51) {
            std::cout << "Final attack attempt: ";
            scav4.attack("LastTarget");
        }
    }
    
    // Test with destroyed ScavTrap
    std::cout << "\n--- Destroyed ScavTrap Test ---" << std::endl;
    ScavTrap scav5("Doomed");
    scav5.takeDamage(150); // Destroy it
    scav5.attack("Target");
    scav5.guardGate();
    
    // Compare ClapTrap vs ScavTrap
    std::cout << "\n--- ClapTrap vs ScavTrap Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("SuperBot");
    
    std::cout << "ClapTrap attack: ";
    clap.attack("TestTarget");
    std::cout << "ScavTrap attack: ";
    scav.attack("TestTarget");
    
    std::cout << "\n--- Destruction Chaining (reverse order) ---" << std::endl;
    
    return 0;
}