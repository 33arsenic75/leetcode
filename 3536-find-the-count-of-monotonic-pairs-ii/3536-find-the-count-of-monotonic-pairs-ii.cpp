class Solution {
public:
    int MOD = 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1(n);
        vector<int> arr2(n);
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for (int j = 0; j <= nums[0]; j++)
            dp[0][j] = 1;
        for (int i = 1; i < n; i++){
            int ways = 0;
            int k = 0;
            for (int j = 0; j <= nums[i]; j++){
                if (k <= min(j, j - (nums[i] - nums[i - 1]))){
                    ways = (ways + dp[i - 1][k]) % MOD;
                    k++;
                }
                dp[i][j] = ways;
            }
        }
        int res = 0;
        for (int i = 0; i <= 1000; i++)
            res = (res + dp[n - 1][i]) % MOD;
        return res;
    }
};