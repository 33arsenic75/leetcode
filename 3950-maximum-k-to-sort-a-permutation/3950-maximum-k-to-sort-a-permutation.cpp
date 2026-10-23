class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) ans &= i;
        }
        return ans == -1 ? 0 : ans;
    }
};

/// Wrong Positions
/// 11
/// 01
 
/// 11
/// 10
/// 100
/// 32-clz