#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    std::cout << "=== BASIC MATERIA SYSTEM TEST ===" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    
    AMateria* iceTemplate = new Ice();
    AMateria* cureTemplate = new Cure();
    src->learnMateria(iceTemplate);
    src->learnMateria(cureTemplate);
    delete iceTemplate;
    delete cureTemplate;
    
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    
    std::cout << "\n=== EQUIP AND USE MATERIAS ===\n" << std::endl;
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    tmp = src->createMateria("fire");
    if (tmp) me->equip(tmp);
    
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    
    std::cout << "\n=== UNEQUIP TEST ===\n" << std::endl;
    
    AMateria* unequippedIce = src->createMateria("ice");
    me->equip(unequippedIce);
    me->use(2, *bob);
    me->unequip(2);
    me->use(2, *bob);
    delete unequippedIce;
    
    std::cout << "\n=== INVENTORY FULL TEST ===\n" << std::endl;
    
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    
    AMateria* extraIce = src->createMateria("ice");
    me->equip(extraIce);
    delete extraIce;
    
    std::cout << "\n=== DEEP COPY TEST ===\n" << std::endl;
    
    Character original("Alice");
    AMateria* aliceIce = src->createMateria("ice");
    AMateria* aliceCure = src->createMateria("cure");
    original.equip(aliceIce);
    original.equip(aliceCure);
    
    {
        Character copy = original;
        std::cout << "Original and copy are different: " << (&original != &copy ? "YES" : "NO") << std::endl;
        copy.use(0, *bob);
    }
    
    std::cout << "Original still works after copy destruction:" << std::endl;
    original.use(0, *bob);
    
    std::cout << "\n=== MATERIA SOURCE TESTS ===\n" << std::endl;
    
    MateriaSource bigSource;
    AMateria* temp1 = new Ice();
    AMateria* temp2 = new Cure();
    AMateria* temp3 = new Ice();
    AMateria* temp4 = new Cure();
    AMateria* temp5 = new Ice();
    
    bigSource.learnMateria(temp1);
    bigSource.learnMateria(temp2);
    bigSource.learnMateria(temp3);
    bigSource.learnMateria(temp4);
    bigSource.learnMateria(temp5);
    
    delete temp1;
    delete temp2;
    delete temp3;
    delete temp4;
    delete temp5;
    
    std::cout << "\n=== CLEANUP ===\n" << std::endl;
    
    delete bob;
    delete me;
    delete src;
    
    return 0;
}
