#include <iostream>
#include <vector>
#include "Angle.h"

int main() {
    std::cout << std::boolalpha;

    Angle a(45, 30);
    Angle b(45, 30); 
    Angle c(60, 0); 

    std::cout << "a == b: " << (a == b) << " (expected: true)\n";
    std::cout << "a != c: " << (a != c) << " (expected: true)\n";
    std::cout << "a < c:  " << (a < c) << " (expected: true)\n";
    std::cout << "c > a:  " << (c > a) << " (expected: true)\n";
    std::cout << "a >= b: " << (a >= b) << " (expected: true)\n";

    return 0;
}