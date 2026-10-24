using ll = unsigned long long;
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<ll>dp(amount+1, 0);

        dp[0] = 1;

        for(int coin: coins){
            for(int total = coin; total <= amount ; total ++){
                dp[total] += dp[total-coin];
            }
        }

        return (int)dp[amount];
    }
};