#include <iostream>
#include <vector>
#include "fun.h"

int main() {
	//int numCity,startCity;
 //   char fillMethod = ' ';
 //   CostMatrix matrixCost;

 //   std::cout << "Enter number of cities: ";
 //   numCity = cheсkValue();

 //   while (true) {
 //       std::cout << "Select the matrix filling method (r - random, w - manual): ";
 //       std::cin >> fillMethod;
 //       if (fillMethod == 'r' || fillMethod == 'w') {
 //           break;
 //       }
 //       std::cout << "Incorrect input! Please enter 'r' or 'w'.\n\n";
 //   }

 //   matrixCost = CreateMatrix(numCity,fillMethod);

 //   printMatrix(matrixCost);

 //   std::cout << "Enter start city: ";
 //   startCity = cheсkValue();


 //   TspResult result;
 //   
 //   result = searchSolution(matrixCost, numCity, startCity-1);

 //   std::cout << "exact solution\n";
 //   printPath(result);

 //   TspResult greedyResult;

 //   greedyResult = greedySearchSolution(matrixCost, numCity, startCity - 1);

 //   std::cout << "greedy solution\n";
 //   printPath(greedyResult);
	runFullReport();
	return 0;
}