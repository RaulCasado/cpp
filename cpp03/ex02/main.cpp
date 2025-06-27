#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Testing All Three Classes ===" << std::endl;
    
    // Test construction chaining for all classes
    std::cout << "\n--- Construction Chaining Test ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("WarBot");
    
    // Test copy constructors
    std::cout << "\n--- Copy Constructor Tests ---" << std::endl;
    ScavTrap scav2(scav);
    FragTrap frag2(frag);
    
    // Test assignment operators
    std::cout << "\n--- Assignment Operator Tests ---" << std::endl;
    ScavTrap scav3("TempGuard");
    FragTrap frag3("TempWar");
    scav3 = scav;
    frag3 = frag;
    
    // Test attacks comparison
    std::cout << "\n--- Attack Comparison Tests ---" << std::endl;
    std::cout << "ClapTrap attack: ";
    clap.attack("Target");
    std::cout << "ScavTrap attack: ";
    scav.attack("Target");
    std::cout << "FragTrap attack: ";
    frag.attack("Target");
    
    // Test special abilities
    std::cout << "\n--- Special Abilities Test ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    
    // Test damage and repair
    std::cout << "\n--- Damage and Repair Tests ---" << std::endl;
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();
    
    // Test energy depletion for FragTrap (100 energy)
    std::cout << "\n--- FragTrap Energy Test ---" << std::endl;
    FragTrap energyTest("EnergyBot");
    for (int i = 0; i < 5; i++) {
        energyTest.attack("EnemyBot");
    }
    
    // Test destroyed FragTrap
    std::cout << "\n--- Destroyed FragTrap Test ---" << std::endl;
    FragTrap deadBot("DeadBot");
    deadBot.takeDamage(150);
    deadBot.attack("Target");
    deadBot.highFivesGuys();
    
    // Stats comparison
    std::cout << "\n--- Stats Summary ---" << std::endl;
    std::cout << "ClapTrap: HP(10), Energy(10), Attack(0)" << std::endl;
    std::cout << "ScavTrap: HP(100), Energy(50), Attack(20)" << std::endl;
    std::cout << "FragTrap: HP(100), Energy(100), Attack(30)" << std::endl;
    
    std::cout << "\n--- Destruction Chaining (reverse order) ---" << std::endl;
    
    return 0;
}