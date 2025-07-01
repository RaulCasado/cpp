#include "ScalarConverter.hpp"
#include <sstream>
#include <cfloat>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        convertPseudoLiteral(literal);
        return;
    }
    
    if (isChar(literal))
    {
        char c = literal[1];
        convertFromChar(c);
    }
    else if (isInt(literal))
    {
        long value = std::strtol(literal.c_str(), NULL, 10);
        if (value > INT_MAX || value < INT_MIN)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        convertFromInt(static_cast<int>(value));
    }
    else if (isFloat(literal))
    {
        float value = std::strtof(literal.c_str(), NULL);
        convertFromFloat(value);
    }
    else if (isDouble(literal))
    {
        double value = std::strtod(literal.c_str(), NULL);
        convertFromDouble(value);
    }
    else
    {
        std::cout << "Error: Invalid literal format" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && isDisplayable(literal[1]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
    
    for (size_t i = start; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    std::string without_f = literal.substr(0, literal.length() - 1);
    
    if (without_f.empty())
        return false;
    
    size_t start = 0;
    if (without_f[0] == '+' || without_f[0] == '-')
        start = 1;
    
    bool has_dot = false;
    for (size_t i = start; i < without_f.length(); i++)
    {
        if (without_f[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (!std::isdigit(without_f[i]))
            return false;
    }
    return has_dot;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    bool has_dot = false;
    for (size_t i = start; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return has_dot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return (literal == "nan" || literal == "nanf" || 
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

void ScalarConverter::convertFromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int value)
{
    // char
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isDisplayable(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    // int
    std::cout << "int: " << value << std::endl;
    
    // float
    std::cout << "float: " << static_cast<float>(value);
    if (static_cast<float>(value) == static_cast<int>(static_cast<float>(value)))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    
    // double
    std::cout << "double: " << static_cast<double>(value);
    if (static_cast<double>(value) == static_cast<int>(static_cast<double>(value)))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
    // char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isDisplayable(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    // int
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    // float
    std::cout << "float: " << value;
    if (value == static_cast<int>(value) && !std::isnan(value) && !std::isinf(value))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    
    // double
    std::cout << "double: " << static_cast<double>(value);
    if (value == static_cast<int>(value) && !std::isnan(value) && !std::isinf(value))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(double value)
{
    // char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isDisplayable(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    // int
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    // float
    if (value > FLT_MAX || value < -FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(value);
        if (value == static_cast<int>(value) && !std::isnan(value) && !std::isinf(value))
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
    
    // double
    std::cout << "double: " << value;
    if (value == static_cast<int>(value) && !std::isnan(value) && !std::isinf(value))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nanf" || literal == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inff" || literal == "+inf" || literal == "inff" || literal == "inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

bool ScalarConverter::isDisplayable(char c)
{
    return (c >= 32 && c <= 126);
}