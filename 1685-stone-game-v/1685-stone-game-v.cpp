
class Solution {
public:
    vector<int> sum;
    vector<vector<int>> dp;

    int solve(int i, int j) {
        if (i >= j) return 0;

        int& ans = dp[i][j];
        if (ans != -1) return ans;

        ans = 0;

        for (int k = i; k < j; k++) {
            int sum1 = sum[k] - sum[i - 1];
            int sum2 = sum[j] - sum[k];

            if (sum1 < sum2) {
                ans = max(ans, sum1 + solve(i, k));
            } 
            else if (sum1 > sum2) {
                ans = max(ans, sum2 + solve(k + 1, j));
            } 
            else {
                ans = max(ans, sum1 + solve(i, k));
                ans = max(ans, sum2 + solve(k + 1, j));
            }
        }

        return ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sum.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stoneValue[i];
        }

        dp.assign(n + 2, vector<int>(n + 2, -1));
        return solve(1, n);
    }
};
