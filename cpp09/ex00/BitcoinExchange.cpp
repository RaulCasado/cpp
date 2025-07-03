#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string rateStr;
        
        if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
            double rate = std::atof(rateStr.c_str());
            _database[date] = rate;
        }
    }
    
    file.close();
    return true;
}

void BitcoinExchange::processFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;
        
        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            // Trim whitespace
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            
            if (!isValidDate(date)) {
                printError("bad input => " + date);
                continue;
            }
            
            if (!isValidValue(valueStr)) {
                if (valueStr.find('-') != std::string::npos) {
                    printError("not a positive number.");
                } else {
                    printError("too large a number.");
                }
                continue;
            }
            
            double value = std::atof(valueStr.c_str());
            double rate = findExchangeRate(date);
            printResult(date, value, rate);
        } else {
            printError("bad input => " + line);
        }
    }
    
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    
    int y = std::atoi(year.c_str());
    int m = std::atoi(month.c_str());
    int d = std::atoi(day.c_str());
    
    if (y < 2009 || y > 2025) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    if (m == 2 && d > 29) return false; 
    
    return true;
}


bool BitcoinExchange::isValidValue(const std::string& value) {
    if (value.empty()) return false;
    
    bool hasDecimal = false;
    size_t start = 0;
    
    if (value[0] == '-' || value[0] == '+') {
        start = 1;
    }
    
    for (size_t i = start; i < value.length(); i++) {
        if (value[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!std::isdigit(value[i])) {
            return false;
        }
    }
    
    double val = std::atof(value.c_str());
    if (val < 0 || val > 1000) {
        return false;
    }
    
    return true;
}

double BitcoinExchange::findExchangeRate(const std::string& date) {
    std::map<std::string, double>::iterator it = _database.find(date);
    if (it != _database.end()) {
        return it->second;
    }
    
    // Find the closest lower date
    std::map<std::string, double>::iterator lower = _database.lower_bound(date);
    if (lower != _database.begin()) {
        --lower;
        return lower->second;
    }
    
    return 0.0;
}

void BitcoinExchange::printResult(const std::string& date, double value, double rate) {
    std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}

void BitcoinExchange::printError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}