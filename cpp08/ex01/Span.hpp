#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    
    Span(const Span& other);
    
    Span& operator=(const Span& other);
    
    ~Span();
    
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    unsigned int size() const;
    unsigned int maxSize() const;
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    unsigned int distance = std::distance(begin, end);
    
    if (_numbers.size() + distance > _maxSize) {
        throw std::runtime_error("Cannot add numbers: would exceed maximum size");
    }
    
    _numbers.insert(_numbers.end(), begin, end);
}

#endif