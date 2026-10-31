class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, -1))
        );

        function<bool(int, int)> inrange = [&](int i, int j) {
            return (i >= 0) && (j >= 0) && (i < n) && (j < m);
        };

        /// dir 0 -> NONE
        /// dir 1 -> Right
        /// dir 2 -> Down
        function<int(int, int, int)> f = [&](int i, int j, int dir) -> int {
            if (!inrange(i, j)) return 0;

            if (i == n - 1 && j == m - 1) return 1;

            if (dp[i][j][dir] != -1)
                return dp[i][j][dir];

            int ans = 0;

            if (grid[i][j] == 0) {
                // Empty cell: can move either right or down
                ans = (f(i, j + 1, 1) + f(i + 1, j, 2)) % MOD;
            }
            else {
                // Mirror: reflect according to incoming direction
                if (dir == 1) {
                    ans = f(i + 1, j, 2);
                }
                else if (dir == 2) {
                    ans = f(i, j + 1, 1);
                }
            }

            return dp[i][j][dir] = ans;
        };

        return f(0, 0, 0);
    }
};