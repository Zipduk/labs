#include <iostream>
#include <vector>
#include "fun.h"

int main() {
	int numCity;
    char fillMethod = ' ';
    CostMatrix matrixCost;

    std::cout << "Enter number of cities: ";
    numCity = cheсkValue();

    while (true) {
        std::cout << "Select the matrix filling method (r - random, w - manual): ";
        std::cin >> fillMethod;
        if (fillMethod == 'r' || fillMethod == 'w') {
            break;
        }
        std::cout << "Incorrect input! Please enter 'r' or 'w'.\n\n";
    }

    matrixCost = CreateMatrix(numCity,fillMethod);


	return 0;
}