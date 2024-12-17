class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==original)original*=2;
        }
        return original;
    }
};