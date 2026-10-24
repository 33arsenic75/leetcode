class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, 0), dp2(n, 0);

        // Case 1: Rob houses [0, n-2], excluding the last house.
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        // Case 2: Rob houses [1, n-1], excluding the first house.
        dp2[1] = nums[1];

        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return max(dp1[n - 2], dp2[n - 1]);
    }
};