#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        void makeSound() const;
};

#endif