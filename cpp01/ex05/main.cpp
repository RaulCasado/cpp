#include "Harl.hpp"

int main() {
    Harl harl;
    
    std::cout << "=== Testing Harl's complaints ===" << std::endl;
    std::cout << std::endl;
    
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    harl.complain("INFO");
    std::cout << std::endl;
    
    harl.complain("WARNING");
    std::cout << std::endl;
    
    harl.complain("ERROR");
    std::cout << std::endl;
    
    harl.complain("INVALID");
    std::cout << std::endl;
    
    harl.complain("debug");
    
    return 0;
}