#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"),
      ScavTrap(),
      FragTrap(),
      name("Default")
{
    this->ClapTrap::hitPoints = 100;  
    this->ClapTrap::energyPoints = 50;
    this->ClapTrap::attackDamage = 30;
    std::cout << "DiamondTrap " << this->name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) 
    : ClapTrap(name + "_clap_name"),
      ScavTrap(),
      FragTrap(),
      name(name)
{
    this->ClapTrap::hitPoints = 100;
    this->ClapTrap::energyPoints = 50;
    this->ClapTrap::attackDamage = 30;
    std::cout << "DiamondTrap " << this->name << " created with parameterized constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      name(other.name)
{
    std::cout << "DiamondTrap " << this->name << " created with copy constructor." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
        std::cout << "DiamondTrap " << this->name << " assigned with assignment operator." << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}