#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = defaultHitPoints;
    this->energyPoints = defaultEnergyPoints;
    this->attackDamage = defaultAttackDamage;
    std::cout << "ScavTrap " << this->name << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = defaultHitPoints;
    this->energyPoints = defaultEnergyPoints;
    this->attackDamage = defaultAttackDamage;
    std::cout << "ScavTrap " << this->name << " created with parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->name << " created with copy constructor." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << this->name << " assigned with copy assignment operator." << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " cannot attack!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " cannot attack!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " ferociously attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}
