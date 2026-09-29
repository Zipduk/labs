#include "fun.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>

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

void printMatrix(const CostMatrix& matrix) {
	int size = static_cast<int>(matrix.size());

	std::cout << "\n=== COST MATRIX ===\n\n";

	std::cout << "      ";
	for (int j = 0; j < size; ++j) {
		std::cout << std::setw(4) << (j + 1);
	}
	std::cout << "\n";

	std::cout << "     +" << std::string(size * 4, '-') << "\n";

	for (int i = 0; i < size; ++i) {
		std::cout << std::setw(4) << (i + 1) << " |";

		for (int j = 0; j < size; ++j) {
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

TspResult greedySearchSolution(CostMatrix matrixPrice, int numCity, int startCity) {
	std::vector<bool> visited(numCity, false);
	std::vector<int> path;
	int totalCost = 0;

	int currentCity = startCity;

	path.push_back(currentCity);
	visited[currentCity] = true;

	for (int step = 0; step < numCity - 1; step++) {
		int nearestCity = -1;
		int minCost = 11*numCity;

		for (int nextCity = 0; nextCity < numCity; nextCity++) {
			if (!visited[nextCity] && matrixPrice[currentCity][nextCity] < minCost) {
				minCost = matrixPrice[currentCity][nextCity];
				nearestCity = nextCity;
			}
		}

		currentCity = nearestCity;
		path.push_back(currentCity);
		visited[currentCity] = true;
		totalCost += minCost;
	}

	totalCost += matrixPrice[currentCity][startCity];
	path.push_back(startCity);

	TspResult result;
	result.path = path;
	result.totalCost = totalCost;

	return result;
}