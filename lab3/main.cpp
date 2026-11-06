#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "shell_sort.h"

using namespace std;

int main() {
    int sizes[3] = { 10000, 100000, 1000000 };
    int ranges[3] = { 10, 1000, 100000 };
    int methods[3] = { SHELL, HIBBARD, SEDGEWICK };
    string names[3] = { "Shell", "Hibbard", "Sedgewick" };
    int runs = 3;

    cout << fixed << setprecision(3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string file = "data/arr_" + to_string(sizes[i]) + "_" + to_string(ranges[j]) + ".txt";
            ifstream in(file);
            if (!in) {
                cout << "Cannot open " << file << " (run ./generate first)\n";
                return 1;
            }
            int n;
            in >> n;
            vector<int> a(n);
            for (int& x : a) in >> x;

            cout << "\nArray: size " << n << ", values from -" << ranges[j] << " to " << ranges[j] << "\n";

            for (int m = 0; m < 3; m++) {
                double total = 0;
                bool ok = true;
                for (int run = 0; run < runs; run++) {
                    vector<int> b = a;

                    auto start = chrono::steady_clock::now();
                    shellSort(b, methods[m]);
                    auto end = chrono::steady_clock::now();

                    if (!isSorted(b)) ok = false;
                    total += chrono::duration<double, milli>(end - start).count();
                }
                cout << "  " << names[m] << ": average " << total / runs << " ms, "
                    << (ok ? "sorted correctly" : "NOT SORTED") << "\n";
            }
        }
    }
    return 0;
}