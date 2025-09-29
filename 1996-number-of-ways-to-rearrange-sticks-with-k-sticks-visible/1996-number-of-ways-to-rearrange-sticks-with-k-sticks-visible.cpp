using ll = long long;
class Solution {
public:
    const ll mod = 1e9 + 7;
    int rearrangeSticks(int n, int k) {
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
        dp[0][0] = 1; // base case

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i-1][j-1] + (ll)(i-1) * dp[i-1][j]) % mod;
            }
        }
        return dp[n][k];
    }
};
