class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;

                int score = 0;
                score = max(score, nums[i] + min(
                    (i + 2 <= j) ? dp[i + 2][j] : 0,
                    (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0
                ));

                score = max(score, nums[j] + min(
                    (i <= j - 2) ? dp[i][j - 2] : 0,
                    (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0
                ));

                dp[i][j] = score;
            }
        }

        int total = 0;
        for (int x : nums)
            total += x;

        return dp[0][n - 1] >= total - dp[0][n - 1];
    }
};