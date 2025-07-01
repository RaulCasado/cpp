#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(NULL)));
        seeded = true;
    }
    
    int random = rand() % 3;
    
    switch (random)
    {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return new A();
    }
}

void identify(Base* p)
{
    if (p == 0)
    {
        std::cout << "Identified (pointer): nullptr" << std::endl;
        return;
    }
    
    if (dynamic_cast<A*>(p))
        std::cout << "Identified (pointer): A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified (pointer): B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified (pointer): C" << std::endl;
    else
        std::cout << "Identified (pointer): Unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified (reference): A" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified (reference): B" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified (reference): C" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    std::cout << "Identified (reference): Unknown type" << std::endl;
}
