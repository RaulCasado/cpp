#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    
    void initInventory();
    void clearInventory();

public:
    Character();
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif