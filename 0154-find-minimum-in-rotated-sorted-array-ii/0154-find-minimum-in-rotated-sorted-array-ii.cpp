class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int m;
        while(i<j){
            m = i + (j-i)/2;
            if(nums[m]>nums[j])i=m+1; 
            else  if(nums[m]<nums[j])j=m;
            else j--;
        }
        return nums[i];
    }
};