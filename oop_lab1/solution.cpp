#include <iostream>
#include <vector>
#include "Angle.h"

int main() {
    Angle a(350, 0);
    std::cout << "Initial angle a: " << a.getDegrees() << " deg " << a.getMinutes() << " min\n";
    a += Angle(20, 0); 
    std::cout << "After a += 20 deg: " << a.getDegrees() << " deg " << a.getMinutes() << " min (expected: 10 deg)\n";
    a -= Angle(30, 0);
    std::cout << "After a -= 30 deg: " << a.getDegrees() << " deg " << a.getMinutes() << " min (expected: 340 deg)\n";
    Angle b(10, 45);
    b += Angle(0, 30); 
    std::cout << "After b += 30 min: " << b.getDegrees() << " deg " << b.getMinutes() << " min (expected: 11 deg 15 min)\n";

    return 0;
}