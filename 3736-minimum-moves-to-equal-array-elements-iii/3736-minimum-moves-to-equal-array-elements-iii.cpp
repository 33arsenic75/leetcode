class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        return nums.size() * max_val - accumulate(nums.begin(), nums.end(), 0);
    }
};