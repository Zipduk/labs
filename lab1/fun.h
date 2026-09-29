#include <vector>
#include <iomanip>

using CostMatrix = std::vector<std::vector<int>>;

struct TspResult {
    std::vector<int> path;       
    int totalCost = 0;        
};

CostMatrix CreateMatrix(int NumCity, char method);
int cheсkValue();
TspResult searchSolution(CostMatrix matrixPrice, int numCity, int startCity);
void printPath(const TspResult& result);
void printMatrix(const CostMatrix& matrix);
TspResult greedySearchSolution(CostMatrix matrixPrice, int numCity, int startCity);