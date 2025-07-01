#include "Data.hpp"

Data::Data() : name(""), value(0), price(0.0)
{
}

Data::Data(const Data& other) : name(other.name), value(other.value), price(other.price)
{
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        name = other.name;
        value = other.value;
        price = other.price;
    }
    return *this;
}

Data::~Data()
{
}

Data::Data(const std::string& n, int v, double p) : name(n), value(v), price(p)
{
}
