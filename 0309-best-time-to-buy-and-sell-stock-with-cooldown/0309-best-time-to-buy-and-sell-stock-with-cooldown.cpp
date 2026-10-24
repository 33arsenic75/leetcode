class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 2, 0);   // dp[n] = dp[n+1] = 0
        int best = INT_MIN;         // max over j > i of prices[j] + dp[j+2]

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];                                  // skip day i
            if (best != INT_MIN)
                dp[i] = max(dp[i], best - prices[i]);           // buy at i
            best = max(best, prices[i] + dp[i + 2]);            // day i as a sell day for earlier buys
        }
        return dp[0];
    }
};