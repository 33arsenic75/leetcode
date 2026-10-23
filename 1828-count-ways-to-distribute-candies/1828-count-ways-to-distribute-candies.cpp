// typedef long long ll;
// const ll MOD = (ll)1e9 + 7;

// class Solution {
// public:
//     vector<vector<ll>> dp;

//     ll solve(int n, int k) {
//         if (n < k || k == 0) return 0;
//         if (n == k || k == 1) return 1;

//         ll &ans = dp[n][k];
//         if (ans != -1) return ans;

//         return ans = (solve(n - 1, k - 1)
//                     + k * solve(n - 1, k) % MOD) % MOD;
//     }

//     int waysToDistribute(int n, int k) {
//         dp.assign(n + 1, vector<ll>(k + 1, -1));
//         return solve(n, k);
//     }
// };


// class Solution {
// public:
//     int waysToDistribute(int n, int k) {
//         const int MOD = 1e9 + 7;
//         vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
//         dp[0][0] = 1;
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= min(i, k); j++) {
//                 dp[i][j] = (dp[i-1][j-1] + (long long)j * dp[i-1][j]) % MOD;
//             }
//         }
//         return (int)dp[n][k];
//     }
// };


class Solution {
public:
    int waysToDistribute(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = min(i, k); j >= 1; j--) {
                dp[j] = (dp[j - 1] + j * dp[j]) % MOD;
            }
            dp[0] = 0;
        }

        return dp[k];
    }
};