#include <vector>

using CostMatrix = std::vector<std::vector<int>>;

struct TspResult {
    std::vector<int> path;       
    long long totalCost = 0;     
    bool isFound = false;        
};

CostMatrix CreateMatrix(int NumCity, char method);
int cheсkValue();