#pragma once
#include <vector>

const int SHELL = 1;
const int HIBBARD = 2;
const int SEDGEWICK = 3;

bool isSorted(const std::vector<int>& a);

void shellSort(std::vector<int>& a, int method);
