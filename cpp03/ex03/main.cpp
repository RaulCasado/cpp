#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== DIAMOND PROBLEM SOLUTION ===" << std::endl;
    
    // Test construction chaining
    std::cout << "\n--- Construction Chaining ---" << std::endl;
    DiamondTrap diamond("Warrior");
    
    // Test copy constructor
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    DiamondTrap diamond2(diamond);
    
    // Test assignment
    std::cout << "\n--- Assignment Operator ---" << std::endl;
    DiamondTrap diamond3("Temp");
    diamond3 = diamond;
    
    // Test whoAmI
    std::cout << "\n--- Who Am I ---" << std::endl;
    diamond.whoAmI();
    diamond2.whoAmI();
    diamond3.whoAmI();
    
    // Test inherited abilities
    std::cout << "\n--- Inherited Abilities ---" << std::endl;
    diamond.attack("Enemy");           // ScavTrap version
    diamond.guardGate();               // ScavTrap ability
    diamond.highFivesGuys();           // FragTrap ability
    
    // Test stats
    std::cout << "\n--- Stats Test ---" << std::endl;
    diamond.takeDamage(50);            // Should have 50 HP left
    diamond.beRepaired(25);            // Should have 75 HP
    diamond.attack("Another Enemy");   // Should still work
    
    // Test energy depletion
    std::cout << "\n--- Energy Test ---" << std::endl;
    DiamondTrap energyTest("EnergyBot");
    for (int i = 0; i < 52; i++) {     // 50 energy from ScavTrap
        if (i < 10) {
            energyTest.attack("Target");
        } else if (i == 51) {
            std::cout << "Final attack: ";
            energyTest.attack("LastTarget");
        }
    }
    
    // Compare all classes
    std::cout << "\n--- Class Comparison ---" << std::endl;
    ClapTrap clap("Basic");
    ScavTrap scav("Guard");
    FragTrap frag("War");
    DiamondTrap dia("Hybrid");
    
    std::cout << "ClapTrap attack: ";
    clap.attack("Target");
    std::cout << "ScavTrap attack: ";
    scav.attack("Target");
    std::cout << "FragTrap attack: ";
    frag.attack("Target");
    std::cout << "DiamondTrap attack: ";
    dia.attack("Target");
    
    std::cout << "\n--- Special Abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    dia.whoAmI();
    
    std::cout << "\n--- Stats Summary ---" << std::endl;
    std::cout << "ClapTrap:    HP(10),  Energy(10),  Attack(0)" << std::endl;
    std::cout << "ScavTrap:    HP(100), Energy(50),  Attack(20)" << std::endl;
    std::cout << "FragTrap:    HP(100), Energy(100), Attack(30)" << std::endl;
    std::cout << "DiamondTrap: HP(100), Energy(50),  Attack(30)" << std::endl;
    
    std::cout << "\n--- Destruction Time ---" << std::endl;
    
    return 0;
}