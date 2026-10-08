#include <iostream>
#include <vector>
#include "Angle.h"

int main() {
    Angle a = Angle::createAngle(), b(20, 12);

    a.printAngle();

    return 0;
}