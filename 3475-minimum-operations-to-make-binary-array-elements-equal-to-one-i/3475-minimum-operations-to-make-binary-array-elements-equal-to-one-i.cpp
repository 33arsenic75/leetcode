class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0 , n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++){
            if(!nums[i]){
                for(int j = i ; j < i + 3 ; j ++){
                    nums[j] = 1 - nums[j];
                }
                op++;
                // cout<<i<<" ";
            }
        }
        if(nums[n-2] && nums[n-1])return op;
        return -1;   
    }
};