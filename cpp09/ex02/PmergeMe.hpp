#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <algorithm>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void parseInput(int argc, char* argv[]);
    void sortAndDisplay();
    
private:
    bool isValidNumber(const std::string& str);
    void displayBefore();
    void displayAfter();
    
    // Ford-Johnson para vector
    void fordJohnsonVector(std::vector<int>& vec);
    void insertionSortVector(std::vector<int>& vec);
    
    // Ford-Johnson para deque
    void fordJohnsonDeque(std::deque<int>& deq);
    void insertionSortDeque(std::deque<int>& deq);
    
    // Utilidades de tiempo
    double getTime();
    double timeDifference(double start, double end);
};

#endif
