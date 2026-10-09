#include <iostream>
#include <vector>
#include "Angle.h"
#include <iomanip>

int main() {
    Angle b(90, 0), a(120,30),c;

    std::cout << "angle b: ";
    b.printAngle();
    std::cout << "\nangle a: ";
    a.printAngle();

    std::cout << "\ncos b: " << std::fixed <<std::setprecision(3) << b.getCos() << "  sin b: " << b.getSin()<< "  radians b: "<< b.toRadians();
    std::cout << "\ncos a: " << a.getCos() << "  sin a: " << a.getSin() << "  radians a: " << a.toRadians();

    if (a == b) std::cout << " \na==b";
    if (a != b) std::cout << " \na!=b";
    if (a >= b) std::cout << " \na>=b";
    if (a <= b) std::cout << " \na<=b";

    std::cout << "\na+b= ";
    c = a + b;
    c.printAngle();

    std::cout << "\nc+b= ";
    c += b;
    c.printAngle();

    std::cout << "\nc*3= ";
    c = c * 3;
    c.printAngle();

    std::cout << "\nc/2= ";
    c = c / 2;
    c.printAngle();

    return 0;
}
