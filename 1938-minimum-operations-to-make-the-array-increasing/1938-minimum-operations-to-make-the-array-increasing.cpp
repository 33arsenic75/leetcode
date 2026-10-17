class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            if(nums[i]>nums[i-1])continue;
            operations += nums[i-1] - nums[i] +1;
            nums[i] = nums[i-1]+1;
        }
        return operations;
    }
};