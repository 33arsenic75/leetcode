typedef __int128 ll;

class Solution {
public:
    bool solve(int i, ll prod, ll target, vector<int>& nums) {
        if (prod > target) return false;
        if (prod == target) return true;
        if (i == nums.size()) return false;
        
        // Include nums[i]
        if (solve(i + 1, prod * nums[i], target, nums)) return true;

        // Exclude nums[i]
        if (solve(i + 1, prod, target, nums)) return true;

        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        ll total = 1;
        for (int x : nums) {
            total *= x;
            if (total > (ll)target * target) return false;
        }

        if (total != (ll)target * target) return false;

        return solve(0, 1, target, nums);
    }
};