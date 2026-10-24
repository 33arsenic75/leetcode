class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>dp(n+1, 0);
        int best = INT_MIN;
        for(int i = n-1 ; i >= 0 ; i--){
            dp[i] = dp[i+1];
            if(best != INT_MIN)
                dp[i] = max(best - prices[i] - fee, dp[i]);
            best = max(best, dp[i+1] + prices[i]);
        }
        return dp[0];
    }
};


/// dp[i] = dp[i+1]
/// dp[i] = prices[j] + dp[j+1] - prices[i] - fee