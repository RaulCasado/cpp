#include "Fixed.hpp"

Fixed::Fixed() : integerValue(0) {}

Fixed::Fixed(const Fixed &other) : integerValue(other.integerValue) {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        integerValue = other.integerValue;
    }
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int value) : integerValue(value << _fractionalBits) {}

Fixed::Fixed(const float value) : integerValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {}

float Fixed::toFloat(void) const {
    return static_cast<float>(integerValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return integerValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
    return integerValue;
}

void Fixed::setRawBits(int const raw) {
    integerValue = raw;
}

// comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return integerValue > other.integerValue;
}
bool Fixed::operator<(const Fixed &other) const {
    return integerValue < other.integerValue;
}
bool Fixed::operator>=(const Fixed &other) const {
    return integerValue >= other.integerValue;
}
bool Fixed::operator<=(const Fixed &other) const {
    return integerValue <= other.integerValue;
}
bool Fixed::operator==(const Fixed &other) const {
    return integerValue == other.integerValue;
}
bool Fixed::operator!=(const Fixed &other) const {
    return integerValue != other.integerValue;
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(integerValue + other.integerValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(integerValue - other.integerValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((integerValue * other.integerValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.setRawBits((integerValue << _fractionalBits) / other.integerValue);
    return result;
}

// increment/decrement operators
Fixed &Fixed::operator++() {
    integerValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    integerValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}

