class Solution {
public:
    vector<vector<int>> dp;
    const int mod = 1e9 + 7;
    int add(int a, int b) {
        return ((a % mod) + (b % mod)) % mod;
    }
    int mul(int a, int b) {
        return ((long long)(a % mod) * (b % mod)) % mod;
    }
    int numWays(vector<string>& words, string target) {
        int n = target.size(), m = words[0].size();
        vector<vector<int>> cnt(m, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < m; j++) {
                cnt[j][word[j] - 'a']++;
            }
        }
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j - 1];
                if (cnt[j - 1][target[i - 1] - 'a'] > 0) {
                    dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - 1], cnt[j - 1][target[i - 1] - 'a']));
                }
            }
        }

        return dp[n][m];
    }
};
