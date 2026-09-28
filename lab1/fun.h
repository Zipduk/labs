#include <vector>

using CostMatrix = std::vector<std::vector<int>>;

struct TspResult {
    std::vector<int> path;       
    int totalCost = 0;        
};

CostMatrix CreateMatrix(int NumCity, char method);
int cheсkValue();
TspResult searchSolution(CostMatrix matrixPrice, int numCity, int startCity);
void printPath(const TspResult& result);