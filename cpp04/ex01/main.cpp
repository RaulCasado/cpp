#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== BASIC POLYMORPHISM TEST ===" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i; // should not create a leak
    
    std::cout << "\n=== ARRAY OF ANIMALS TEST ===" << std::endl;
    
    const int arraySize = 6;
    Animal* animals[arraySize];
    
    // Fill array: half dogs, half cats
    for (int idx = 0; idx < arraySize; idx++) {
        if (idx < arraySize / 2) {
            animals[idx] = new Dog();
        } else {
            animals[idx] = new Cat();
        }
    }
    
    std::cout << "\nMaking sounds:" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << "Animal " << idx << " (" << animals[idx]->getType() << "): ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\nDeleting animals:" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        delete animals[idx]; // Delete as Animal*, destructors should be called properly
    }
    
    std::cout << "\n=== DEEP COPY TEST ===" << std::endl;
    
    std::cout << "\n--- Dog deep copy test ---" << std::endl;
    Dog originalDog;
    {
        Dog copiedDog = originalDog; // Copy constructor
        std::cout << "Dogs are different objects: " << (&originalDog != &copiedDog ? "YES" : "NO") << std::endl;
    } // copiedDog destroyed here
    std::cout << "Original dog still exists after copy destruction" << std::endl;
    
    std::cout << "\n--- Cat deep copy test ---" << std::endl;
    Cat originalCat;
    {
        Cat copiedCat = originalCat; // Copy constructor
        std::cout << "Cats are different objects: " << (&originalCat != &copiedCat ? "YES" : "NO") << std::endl;
    } // copiedCat destroyed here
    std::cout << "Original cat still exists after copy destruction" << std::endl;
    
    std::cout << "\n--- Assignment operator test ---" << std::endl;
    Dog dog1;
    Dog dog2;
    
    std::cout << "Before assignment - different dogs" << std::endl;
    dog1 = dog2; // Assignment operator
    std::cout << "After assignment - should have deep copied brains" << std::endl;
    
    return 0;
}