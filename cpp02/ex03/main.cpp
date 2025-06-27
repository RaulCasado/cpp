#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.0f);
    Point outside(10.0f, 10.0f);
    Point onEdge(2.5f, 0.0f);
    Point onVertex(0.0f, 0.0f);

    std::cout << "=== BSP Tests ===" << std::endl;
    std::cout << "Point inside (2.5, 2.0): " << (bsp(a, b, c, inside) ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Point outside (10, 10): " << (bsp(a, b, c, outside) ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Point on edge (2.5, 0): " << (bsp(a, b, c, onEdge) ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Point on vertex (0, 0): " << (bsp(a, b, c, onVertex) ? "TRUE" : "FALSE") << std::endl;

    return 0;
}
