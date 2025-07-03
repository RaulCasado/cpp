#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        processToken(token);
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }
    
    return _stack.top();
}

void RPN::processToken(const std::string& token) {
    if (isNumber(token)) {
        int num = std::atoi(token.c_str());
        _stack.push(num);
    } else if (isOperator(token)) {
        if (_stack.size() < 2) {
            throw std::runtime_error("Error: insufficient operands");
        }
        
        int b = _stack.top();
        _stack.pop();
        int a = _stack.top();
        _stack.pop();
        
        int result = performOperation(a, b, token[0]);
        _stack.push(result);
    } else {
        throw std::runtime_error("Error: invalid token");
    }
}

bool RPN::isNumber(const std::string& token) {
    if (token.empty()) return false;
    
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+') {
        start = 1;
        if (token.length() == 1) return false;
    }
    
    for (size_t i = start; i < token.length(); i++) {
        if (!std::isdigit(token[i])) {
            return false;
        }
    }
    
    return true;
}

bool RPN::isOperator(const std::string& token) {
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || 
            token[0] == '*' || token[0] == '/');
}

int RPN::performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}