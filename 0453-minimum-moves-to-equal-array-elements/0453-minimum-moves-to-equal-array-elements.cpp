class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int ans = accumulate(nums.begin(), nums.end(), 0) - nums.size() * min;
        return ans;
    }
};


//// decrement 1 by 1