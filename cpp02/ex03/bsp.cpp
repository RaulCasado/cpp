#include "Point.hpp"

float calculateArea(const Point a, const Point b, const Point c) {
    float result =  (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
            b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
            c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;

    return result < 0 ? -result : result;
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
    float areaABC = calculateArea(a, b, c);
    float areaPAB = calculateArea(point, a, b);
    float areaPBC = calculateArea(point, b, c);
    float areaPAC = calculateArea(point, a, c);
    
    if (areaPAB + areaPBC + areaPAC == areaABC) {
        if (areaPAB > 0 && areaPBC > 0 && areaPAC > 0) {
            return true;
        }
    }
    
    return false;
}
