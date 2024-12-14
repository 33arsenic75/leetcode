#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define SZ(x) ((int)(x).size())

using int64 = long long;

// Function to compute the floor of log2 of x
int lg2(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

// Function to build the Sparse Table for range minimum queries
vector<vector<int>> buildMinTable(const vector<int>& a) {
    int n = SZ(a);
    int max_k = lg2(n) + 1;
    vector<vector<int>> minTable(max_k, vector<int>(n));

    // Initialize the first row of the table
    minTable[0] = a;

    // Fill the Sparse Table
    for (int k = 1; (1 << k) <= n; ++k) {
        for (int i = 0; i + (1 << k) <= n; ++i) {
            minTable[k][i] = min(minTable[k - 1][i], minTable[k - 1][i + (1 << (k - 1))]);
        }
    }
    return minTable;
}

// Function to build the Sparse Table for range maximum queries
vector<vector<int>> buildMaxTable(const vector<int>& a) {
    int n = SZ(a);
    int max_k = lg2(n) + 1;
    vector<vector<int>> maxTable(max_k, vector<int>(n));

    // Initialize the first row of the table
    maxTable[0] = a;

    // Fill the Sparse Table
    for (int k = 1; (1 << k) <= n; ++k) {
        for (int i = 0; i + (1 << k) <= n; ++i) {
            maxTable[k][i] = max(maxTable[k - 1][i], maxTable[k - 1][i + (1 << (k - 1))]);
        }
    }
    return maxTable;
}

// Query function for Sparse Table
int query(const vector<vector<int>>& table, int x, int y) {
    int k = lg2(y - x + 1);
    return min(table[k][x], table[k][y - (1 << k) + 1]);
}

int queryMax(const vector<vector<int>>& table, int x, int y) {
    int k = lg2(y - x + 1);
    return max(table[k][x], table[k][y - (1 << k) + 1]);
}

class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
        int n = SZ(a);
        auto minTable = buildMinTable(a);
        auto maxTable = buildMaxTable(a);

        int64 result = 0;
        for (int i = 0; i < n; ++i) {
            int low = i, high = n - 1;

            // Binary search to find the largest valid subarray ending at 'high'
            while (low < high) {
                int mid = (low + high + 1) / 2;
                int min_val = query(minTable, i, mid);
                int max_val = queryMax(maxTable, i, mid);

                if (max_val - min_val > 2) {
                    high = mid - 1;
                } else {
                    low = mid;
                }
            }

            // Add the count of valid subarrays starting at index 'i'
            result += high - i + 1;
        }
        return result;
    }
};