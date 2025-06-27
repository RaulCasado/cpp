#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() const {
    std::cout << name << " Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

std::string Zombie::getName() const {
    return name;
}