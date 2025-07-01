#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CORRECT POLYMORPHISM TEST ===" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Types:" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output the animal sound!
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== WRONG POLYMORPHISM TEST ===" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "Wrong sounds (should be the same):" << std::endl;
    wrongMeta->makeSound(); // WrongAnimal sound
    wrongCat->makeSound();  // Should also be WrongAnimal sound (not polymorphic)
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== DIRECT INSTANTIATION TEST ===" << std::endl;
    
    Animal animal;
    Dog dog;
    Cat cat;
    
    std::cout << "Direct calls:" << std::endl;
    animal.makeSound();
    dog.makeSound();
    cat.makeSound();
    
    return 0;
}