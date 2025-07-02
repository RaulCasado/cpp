#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>

int main() {
    std::cout << "=== Basic MutantStack test (from subject) ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;  // 17
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;  // 1
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\n=== Iterating with normal iterators ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Stack contents (insertion order): ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Iterating with reverse iterators (LIFO order) ===" << std::endl;
    std::cout << "Stack contents (LIFO order): ";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Copy constructor test ===" << std::endl;
    std::stack<int> s(mstack);  // Copy to normal stack
    std::cout << "Copied to std::stack, size: " << s.size() << std::endl;
    
    std::cout << "\n=== Comparison with std::list ===" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);  // push() becomes push_back()
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "List contents: ";
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    for (; lit != lite; ++lit) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Advanced tests ===" << std::endl;
    
    // Test with different types
    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("42");
    
    std::cout << "String stack: ";
    MutantStack<std::string>::iterator sit = stringStack.begin();
    MutantStack<std::string>::iterator site = stringStack.end();
    for (; sit != site; ++sit) {
        std::cout << *sit << " ";
    }
    std::cout << std::endl;
    
    // Test const iterators
    const MutantStack<int> constStack(mstack);
    std::cout << "Const stack (with const iterators): ";
    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();
    for (; cit != cite; ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    // Test assignment
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;
    
    // Test empty stack
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    std::cout << "Empty stack begin == end: " << (emptyStack.begin() == emptyStack.end()) << std::endl;
    
    return 0;
}