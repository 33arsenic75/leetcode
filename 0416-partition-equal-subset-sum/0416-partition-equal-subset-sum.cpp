class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case
        dp[0][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
};
