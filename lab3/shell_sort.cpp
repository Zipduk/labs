#include "shell_sort.h"

using namespace std;

bool isSorted(const vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i - 1] > a[i]) return false;
    }
    return true;
}

static vector<int> getGaps(int n, int method) {
    vector<int> gaps;
    if (method == SHELL) {
        for (int g = n / 2; g > 0; g /= 2) gaps.insert(gaps.begin(), g);
    } else if (method == HIBBARD) {
        for (int g = 1; g < n; g = 2 * g + 1) gaps.push_back(g);
    } else {
        for (int k = 0;; k++) {
            int g;
            if (k % 2 == 0) g = 9 * ((1 << k) - (1 << (k / 2))) + 1;
            else            g = 8 * (1 << k) - 6 * (1 << ((k + 1) / 2)) + 1;
            if (g >= n) break;
            gaps.push_back(g);
        }
    }
    return gaps;
}

void shellSort(vector<int>& a, int method) {
    int n = a.size();
    vector<int> gaps = getGaps(n, method);
    for (int k = (int)gaps.size() - 1; k >= 0; k--) {
        int gap = gaps[k];
        for (int i = gap; i < n; i++) {
            int tmp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > tmp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
}
