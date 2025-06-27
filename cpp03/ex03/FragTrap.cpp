#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoints = defaultHitPoints;
    this->energyPoints = defaultEnergyPoints;
    this->attackDamage = defaultAttackDamage;
    std::cout << "FragTrap " << this->name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = defaultHitPoints;
    this->energyPoints = defaultEnergyPoints;
    this->attackDamage = defaultAttackDamage;
    std::cout << "FragTrap " << this->name << " created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->name << " created with copy constructor." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << this->name << " assigned using assignment operator." << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "FragTrap " << this->name << " attacks " << target 
                  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "FragTrap " << this->name << " cannot attack, either out of energy or destroyed." << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    if (this->hitPoints > 0) {
        std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
    } else {
        std::cout << "FragTrap " << this->name << " is destroyed and cannot request a high five." << std::endl;
    }
}