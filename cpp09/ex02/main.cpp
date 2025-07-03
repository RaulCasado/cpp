#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    try {
        PmergeMe pmerge;
        pmerge.parseInput(argc, argv);
        pmerge.sortAndDisplay();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
