#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::runtime_error("Error: No input provided");
    }
    
    for (int i = 1; i < argc; i++) {
        if (!isValidNumber(argv[i])) {
            throw std::runtime_error("Error");
        }
        
        int num = std::atoi(argv[i]);
        if (num < 0) {
            throw std::runtime_error("Error");
        }
        
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+') {
        start = 1;
        if (str.length() == 1) return false;
    }
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    
    return true;
}

void PmergeMe::sortAndDisplay() {
    displayBefore();
    
    // Copiar datos para preservar el original
    std::vector<int> vectorCopy = _vectorData;
    std::deque<int> dequeCopy = _dequeData;
    
    // Medir tiempo para vector
    double startVector = getTime();
    fordJohnsonVector(vectorCopy);
    double endVector = getTime();
    
    // Medir tiempo para deque
    double startDeque = getTime();
    fordJohnsonDeque(dequeCopy);
    double endDeque = getTime();
    
    // Actualizar datos ordenados
    _vectorData = vectorCopy;
    _dequeData = dequeCopy;
    
    displayAfter();
    
    // Mostrar tiempos
    double vectorTime = timeDifference(startVector, endVector);
    double dequeTime = timeDifference(startDeque, endDeque);
    
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

void PmergeMe::displayBefore() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size() && i < 5; i++) {
        std::cout << _vectorData[i] << " ";
    }
    if (_vectorData.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() {
    std::cout << "After: ";
    for (size_t i = 0; i < _vectorData.size() && i < 5; i++) {
        std::cout << _vectorData[i] << " ";
    }
    if (_vectorData.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    
    // Para arrays pequeños, usar insertion sort
    if (vec.size() <= 10) {
        insertionSortVector(vec);
        return;
    }
    
    // Dividir en dos mitades
    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());
    
    // Ordenar recursivamente
    fordJohnsonVector(left);
    fordJohnsonVector(right);
    
    // Merge (combinar las dos mitades ordenadas)
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            vec[k++] = left[i++];
        } else {
            vec[k++] = right[j++];
        }
    }
    
    // Copiar elementos restantes
    while (i < left.size()) vec[k++] = left[i++];
    while (j < right.size()) vec[k++] = right[j++];
}

void PmergeMe::insertionSortVector(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& deq) {
    if (deq.size() <= 1) return;
    
    // Para arrays pequeños, usar insertion sort
    if (deq.size() <= 10) {
        insertionSortDeque(deq);
        return;
    }
    
    // Dividir en dos mitades
    size_t mid = deq.size() / 2;
    std::deque<int> left(deq.begin(), deq.begin() + mid);
    std::deque<int> right(deq.begin() + mid, deq.end());
    
    // Ordenar recursivamente
    fordJohnsonDeque(left);
    fordJohnsonDeque(right);
    
    // Merge (combinar las dos mitades ordenadas)
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            deq[k++] = left[i++];
        } else {
            deq[k++] = right[j++];
        }
    }
    
    // Copiar elementos restantes
    while (i < left.size()) deq[k++] = left[i++];
    while (j < right.size()) deq[k++] = right[j++];
}

void PmergeMe::insertionSortDeque(std::deque<int>& deq) {
    for (size_t i = 1; i < deq.size(); i++) {
        int key = deq[i];
        int j = i - 1;
        
        while (j >= 0 && deq[j] > key) {
            deq[j + 1] = deq[j];
            j--;
        }
        deq[j + 1] = key;
    }
}

double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

double PmergeMe::timeDifference(double start, double end) {
    return end - start;
}
