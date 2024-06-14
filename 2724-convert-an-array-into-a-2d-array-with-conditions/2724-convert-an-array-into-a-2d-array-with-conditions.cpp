class Solution {
public:
    int help(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        while (i < n) {
            while (j < n && nums[j] == nums[i]) j++;
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }

    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = help(nums);
        vector<vector<int>> ans(count);
        int i = 0, j = 0;
        int idx = 0;
        while (i < n) {
            while (j < n && nums[j] == nums[i]) {
                ans[idx].push_back(nums[j]);
                j++;
                idx = (idx + 1) % count;
            }
            i = j;
        }

        return ans;
    }
};
