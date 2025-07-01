#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data original("Test Product", 42, 19.99);
    Data* originalPtr = &original;
    
    std::cout << "=== SERIALIZATION TEST ===" << std::endl;
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Name: " << original.name << std::endl;
    std::cout << "  Value: " << original.value << std::endl;
    std::cout << "  Price: " << original.price << std::endl;
    std::cout << "  Address: " << originalPtr << std::endl;
    
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "\nSerialized value: " << serialized << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "  Name: " << deserialized->name << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    std::cout << "  Price: " << deserialized->price << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    
    std::cout << "\n=== VERIFICATION ===" << std::endl;
    std::cout << "Original pointer == Deserialized pointer: " 
              << (originalPtr == deserialized ? "TRUE" : "FALSE") << std::endl;
    
    std::cout << "Data integrity check: " 
              << (originalPtr->name == deserialized->name &&
                  originalPtr->value == deserialized->value &&
                  originalPtr->price == deserialized->price ? "PASSED" : "FAILED") 
              << std::endl;
    
    return 0;
}