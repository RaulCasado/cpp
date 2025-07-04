#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed {
private:
    int integerValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif
