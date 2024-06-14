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