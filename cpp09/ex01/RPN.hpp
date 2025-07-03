#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;
    
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int calculate(const std::string& expression);
    
private:
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    int performOperation(int a, int b, char op);
    void processToken(const std::string& token);
};

#endif