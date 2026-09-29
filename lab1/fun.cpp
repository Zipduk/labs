#include "fun.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <iomanip>
#include <chrono>

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

	int j = 0, bestCost=11*numCity, worstCost=0;

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

		if (currentCost > worstCost) {
			worstCost = currentCost;
			}

		}

	} while (std::next_permutation(path.begin(), path.end() - 1));

	TspResult result;
	result.path = bestPath;
	result.totalCost = bestCost;
	result.worstCost = worstCost;

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

void runFullReport() {
	// Набор размерностей матриц (по заданию: 4x4, 6x6, 8x8, 10x10)
	std::vector<int> dimensions = { 4, 6, 8, 10 };
	int runsPerDim = 3; // по 3 запуска на каждую размерность
	int minPrice = 1;
	int maxPrice = 100; // разброс цен от 1 до 100

	std::cout << "\n================================= EXPERIMENTAL REPORT =================================\n";
	std::cout << "Range of costs: [" << minPrice << " - " << maxPrice << "]\n\n";

	std::cout << std::setw(6) << "Size"
		<< std::setw(6) << "Run"
		<< std::setw(12) << "Exact(Min)"
		<< std::setw(12) << "Exact(Max)"
		<< std::setw(14) << "Exact Time"
		<< std::setw(14) << "Greedy Cost"
		<< std::setw(15) << "Greedy Time"
		<< std::setw(12) << "Quality\n";
	std::cout << std::string(91, '-') << "\n";

	for (int n : dimensions) {
		for (int run = 1; run <= runsPerDim; ++run) {
			// 1. Создаем случайную матрицу
			CostMatrix matrix = CreateMatrix(n, 'r');
			int startCity = 0;

			// 2. Замеряем время точного алгоритма
			auto startExact = std::chrono::high_resolution_clock::now();
			TspResult exactRes = searchSolution(matrix, n, startCity);
			auto endExact = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> exactDuration = endExact - startExact;

			// 3. Замеряем время жадного алгоритма
			auto startGreedy = std::chrono::high_resolution_clock::now();
			TspResult greedyRes = greedySearchSolution(matrix, n, startCity);
			auto endGreedy = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> greedyDuration = endGreedy - startGreedy;

			// 4. Считаем процент качества
			double quality = 100.0;
			if (exactRes.worstCost != exactRes.totalCost) {
				quality = (double)(exactRes.worstCost - greedyRes.totalCost) /
					(exactRes.worstCost - exactRes.totalCost) * 100.0;
			}
			if (quality < 0.0) quality = 0.0; // защита от выбросов

			// 5. Выводим строку отчета
			std::cout << std::setw(4) << n << "x" << n
				<< std::setw(6) << run
				<< std::setw(12) << exactRes.totalCost
				<< std::setw(12) << exactRes.worstCost
				<< std::setw(11) << std::fixed << std::setprecision(4) << exactDuration.count() << " ms"
				<< std::setw(14) << greedyRes.totalCost
				<< std::setw(12) << std::fixed << std::setprecision(4) << greedyDuration.count() << " ms"
				<< std::setw(11) << std::fixed << std::setprecision(1) << quality << "%\n";
		}
		std::cout << std::string(91, '-') << "\n";
	}
}

