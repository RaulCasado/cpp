#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int integerValue;
    static const int _fractionalBits = 8;

public:
    Fixed();                                    
    Fixed(const Fixed& other);                  
    Fixed& operator=(const Fixed& other);      
    ~Fixed();                                 
    
    Fixed(const int value);                     
    Fixed(const float value);                   
    
    float toFloat(void) const;
    int toInt(void) const;
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif