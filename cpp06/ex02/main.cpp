#include "functions.hpp"
#include "Base.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TYPE IDENTIFICATION TEST ===" << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;
        
        Base* obj = generate();
        
        identify(obj);
        
        identify(*obj);
        
        delete obj;
    }
    
    std::cout << "\n--- Nullptr Test ---" << std::endl;
    Base* null_ptr = 0;
    identify(null_ptr);
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}
