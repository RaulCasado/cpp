#include "Character.hpp"

Character::Character() : name("Unknown") {
    std::cout << "Character default constructor called" << std::endl;
    initInventory();
}

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character parameterized constructor called" << std::endl;
    initInventory();
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    initInventory();
    
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        clearInventory();
        
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    clearInventory();
}

void Character::initInventory() {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << name << " equipped " << m->getType() << std::endl;
            return;
        }
    }
    
    std::cout << name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory slot!" << std::endl;
        return;
    }
    
    if (inventory[idx]) {
        std::cout << name << " unequipped " << inventory[idx]->getType() << std::endl;
        inventory[idx] = NULL;
    } else {
        std::cout << "Slot " << idx << " is already empty!" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory slot!" << std::endl;
        return;
    }
    
    if (inventory[idx]) {
        inventory[idx]->use(target);
    } else {
        std::cout << "No materia in slot " << idx << "!" << std::endl;
    }
}