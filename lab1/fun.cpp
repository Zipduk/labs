#include "fun.h"
#include <iostream>
#include <algorithm>
#include <random>

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

