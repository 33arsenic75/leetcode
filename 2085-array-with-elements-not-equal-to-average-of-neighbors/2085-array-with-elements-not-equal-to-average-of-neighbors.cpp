class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size=nums.size();
        for(int i=1;i<size-1;i++){
            if((nums[i-1]<nums[i] && nums[i]<nums[i+1])||(nums[i-1]>nums[i] && nums[i]>nums[i+1])) 
                swap(nums[i],nums[i+1]);
        }
        return nums;
    }
};