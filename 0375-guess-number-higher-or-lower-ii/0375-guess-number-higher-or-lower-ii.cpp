class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = INT_MAX;

                for (int x = l; x <= r; x++) {
                    int score = x + max(dp[l][x - 1], dp[x + 1][r]);
                    dp[l][r] = min(dp[l][r], score);
                }
            }
        }

        return dp[1][n];
    }
};