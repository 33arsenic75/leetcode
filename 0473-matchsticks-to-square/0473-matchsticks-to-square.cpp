class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        return canPartitionKSubsets(matchsticks, 4);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total % k) return false;

        int target = total / k;
        int n = nums.size();
        int total_subsets = (1 << n);

        vector<int> dp(total_subsets, -1);
        dp[0] = 0;

        for (int mask = 0; mask < total_subsets; mask++) {
            if (dp[mask] == -1) continue;

            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) continue;

                int next_sum = dp[mask] + nums[i];
                if (next_sum > target) continue;

                int next_mask = mask | (1 << i);
                dp[next_mask] = next_sum % target;
            }
        }

        return dp[total_subsets - 1] == 0;
    }
};