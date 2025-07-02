#include "Span.hpp"
#include <climits>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Span is already full");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Need at least 2 numbers to calculate span");
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i-1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Need at least 2 numbers to calculate span");
    }
    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
    return maxElement - minElement;
}

unsigned int Span::size() const {
    return _numbers.size();
}

unsigned int Span::maxSize() const {
    return _maxSize;
}
