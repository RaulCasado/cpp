#include <iostream>
#include <cctype>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (--argc) {
        for (char *p = *++argv; *p; ++p) {
            *p = toupper(*p);
        }
        std::cout << *argv << " ";
    }
    std::cout << std::endl;
    return 0;
}