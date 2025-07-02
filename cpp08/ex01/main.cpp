#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        std::cout << "=== Basic test ===" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // 14
        
        std::cout << "\n=== Exception tests ===" << std::endl;
        try {
            sp.addNumber(99);
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        Span emptySpan(10);
        try {
            emptySpan.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n=== Range iterator test ===" << std::endl;
        Span bigSpan(100);
        
        std::vector<int> numbers;
        for (int i = 0; i < 50; ++i) {
            numbers.push_back(i * 2);
        }
        
        bigSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Added " << bigSpan.size() << " numbers" << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
        
        std::cout << "\n=== Large test (10,000 numbers) ===" << std::endl;
        Span hugeSpan(10000);
        
        std::vector<int> randomNumbers;
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) {
            randomNumbers.push_back(std::rand() % 100000);
        }
        
        hugeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Added " << hugeSpan.size() << " random numbers" << std::endl;
        std::cout << "Shortest span: " << hugeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << hugeSpan.longestSpan() << std::endl;
        
        std::cout << "\n=== Test with list ===" << std::endl;
        Span listSpan(20);
        std::list<int> listNumbers;
        listNumbers.push_back(100);
        listNumbers.push_back(50);
        listNumbers.push_back(75);
        listNumbers.push_back(25);
        
        listSpan.addNumbers(listNumbers.begin(), listNumbers.end());
        std::cout << "Shortest span: " << listSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << listSpan.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}