#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
private:
    static const unsigned int defaultHitPoints = 100;
    static const unsigned int defaultEnergyPoints = 50;
    static const unsigned int defaultAttackDamage = 20;
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};

#endif