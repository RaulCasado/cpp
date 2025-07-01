#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data
{
    std::string name;
    int value;
    double price;

    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

    Data(const std::string& n, int v, double p);
};

#endif
