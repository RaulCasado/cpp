#include "iter.hpp"
#include <string>

void printInt(const int& n) {
    std::cout << n << " ";
}

void printString(const std::string& s) {
    std::cout << s << " ";
}

void doubleInt(int& n) {
    n *= 2;
}

void upperString(std::string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 'a' + 'A';
    }
}

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

int main() {
    std::cout << "=== TESTING ITER FUNCTION ===" << std::endl;
    
    std::cout << "\n1. Testing with integers:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Original: ";
    iter(numbers, numbersSize, printInt);
    std::cout << std::endl;
    
    iter(numbers, numbersSize, doubleInt);
    std::cout << "Doubled:  ";
    iter(numbers, numbersSize, printInt);
    std::cout << std::endl;
    
    std::cout << "\n2. Testing with strings:" << std::endl;
    std::string words[] = {"hello", "world", "cpp", "templates"};
    size_t wordsSize = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Original: ";
    iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    iter(words, wordsSize, upperString);
    std::cout << "Upper:    ";
    iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    std::cout << "\n3. Testing with const array:" << std::endl;
    const int constNumbers[] = {10, 20, 30, 40, 50};
    size_t constSize = sizeof(constNumbers) / sizeof(constNumbers[0]);
    
    std::cout << "Const array: ";
    iter(constNumbers, constSize, printInt);
    std::cout << std::endl;
    
    std::cout << "\n4. Testing with template function:" << std::endl;
    double decimals[] = {1.1, 2.2, 3.3, 4.4};
    size_t decimalsSize = sizeof(decimals) / sizeof(decimals[0]);
    
    std::cout << "Decimals: ";
    iter(decimals, decimalsSize, printElement<double>);
    std::cout << std::endl;
    
    return 0;
}
