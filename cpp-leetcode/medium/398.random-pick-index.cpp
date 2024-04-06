/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, queue<int>> dq;
    Solution(vector<int>& nums) {
        for(int i = 0 ; i< nums.size() ; i++)dq[nums[i]].push(i);
    }
    int pick(int target) {
        int temp = dq[target].front();
        dq[target].pop();
        dq[target].push(temp);
        return temp;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

