#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== TESTING ARRAY CLASS TEMPLATE ===" << std::endl;
    
    std::cout << "\n1. Testing default constructor:" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    std::cout << "\n2. Testing constructor with size:" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    std::cout << "Default initialized values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n3. Testing assignment:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = (i + 1) * 10;
    }
    
    std::cout << "Assigned values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n4. Testing copy constructor:" << std::endl;
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;
    std::cout << "Copied values: ";
    for (unsigned int i = 0; i < copiedArray.size(); i++) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n5. Testing deep copy (modifying original):" << std::endl;
    intArray[0] = 999;
    std::cout << "Original array[0]: " << intArray[0] << std::endl;
    std::cout << "Copied array[0]: " << copiedArray[0] << std::endl;
    
    std::cout << "\n6. Testing assignment operator:" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
    std::cout << "Assigned values: ";
    for (unsigned int i = 0; i < assignedArray.size(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n7. Testing with strings:" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Templates";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n8. Testing exception handling:" << std::endl;
    try {
        std::cout << "Trying to access index 10 in array of size 5..." << std::endl;
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: Out of bounds access!" << std::endl;
    }
    
    try {
        std::cout << "Trying to access index 0 in empty array..." << std::endl;
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: Empty array access!" << std::endl;
    }
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}
