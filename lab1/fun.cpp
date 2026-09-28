#include "fun.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <algorithm>

CostMatrix CreateMatrix(int NumCity, char method) {
	CostMatrix matrix(NumCity, std::vector<int>(NumCity, 0));

	if (method == 'r') {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(1, 10);

		for (int i = 0; i < NumCity; i++) {
			for (int j = i + 1; j < NumCity; j++) {
				matrix[i][j] = dist(gen);
				matrix[j][i] = matrix[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < NumCity; i++) {
			for (int j = i + 1; j < NumCity; j++) {
				std::cout << "Enter cost from city " << i + 1 << " to " << j + 1 << ": ";
				matrix[i][j] = cheсkValue();
				matrix[j][i] = matrix[i][j];
			}
		}
	}

	return matrix;
}

int cheсkValue() {
	int cost = 0;
	while (true) {
		if (std::cin >> cost && cost > 0) {
			return cost;
		}
		
		std::cout << "Error: Invalid input! Please enter a positive number.\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}

}

TspResult searchSolution(CostMatrix matrixPrice, int numCity, int startCity) {
	std::vector<int> path(numCity,0);
	std::vector<int> bestPath;

	int j = 0, bestCost=11*numCity;

	for (int i = 0; i < numCity; i++) {
		if (i != startCity) {
			path[j] = i; 
			j++;
		}
	}
	path[numCity - 1] = startCity;

	do {
		int currentCost = 0, currentCity = startCity;

		for (int nextCity : path) {
			currentCost += matrixPrice[currentCity][nextCity];
			currentCity = nextCity;
		}

		if (bestCost > currentCost) {
			bestCost = currentCost;
			bestPath.clear();
			bestPath.push_back(startCity);

			for (int city : path) {
				bestPath.push_back(city);
			}

		}

	} while (std::next_permutation(path.begin(), path.end() - 1));

	TspResult result;
	result.path = bestPath;
	result.totalCost = bestCost;

	return result;

}

void printPath(const TspResult& result) {
	if (result.path.empty()) {
		std::cout << "\nRoute not found!\n";
		return;
	}

	std::cout << "\nOptimal route: ";
	for (size_t i = 0; i < result.path.size(); ++i) {
		std::cout << result.path[i] + 1;

		if (i + 1 < result.path.size()) {
			std::cout << " -> ";
		}
	}

	std::cout << "\nTotal minimum cost: " << result.totalCost << "\n\n";
}
