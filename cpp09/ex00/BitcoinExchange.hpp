#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    bool loadDatabase(const std::string& filename);
    void processFile(const std::string& filename);
    
private:
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    double findExchangeRate(const std::string& date);
    void printResult(const std::string& date, double value, double rate);
    void printError(const std::string& message);
};

#endif