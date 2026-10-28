template <typename T> auto make_vec(size_t n, T val) {
    return std::vector<T>(n, val);
}

template <typename T, typename... Args> auto make_vec(size_t n, Args... args) {
    return std::vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(args...));
}

const int MAX_VALUE = 1024;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto dp = make_vec<bool>(n, m, MAX_VALUE, false);
        dp[0][0][grid[0][0]] = true;

        for (int i = 1; i < n; i++) {
            for (int k = 0; k < MAX_VALUE; k++) {
                dp[i][0][k] = dp[i - 1][0][k ^ grid[i][0]];
            }
        }

        for (int j = 1; j < m; j++) {
            for (int k = 0; k < MAX_VALUE; k++) {
                dp[0][j][k] = dp[0][j - 1][k ^ grid[0][j]];
            }
        }

        int ans = MAX_VALUE;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int k = 0; k < MAX_VALUE; k++) {
                    dp[i][j][k] = dp[i - 1][j][k ^ grid[i][j]] ||
                                  dp[i][j - 1][k ^ grid[i][j]];
                }
            }
        }
        for (int k = 0; k < MAX_VALUE; k++) {
            if (dp[n - 1][m - 1][k])
                ans = min(ans, k);
        }
        return ans;
    }
};