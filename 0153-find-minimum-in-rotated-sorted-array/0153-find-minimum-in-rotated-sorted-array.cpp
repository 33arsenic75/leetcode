class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1 , m;
        int n = nums.size();
        int ans = nums[0];
        while(i<=j){
            m = i + (j-i)/2;
            if(nums[m]<=nums[0] && nums[m]<=nums[n-1]){
                ans = nums[m];
                j = m - 1;
            }
            else{
                i = m + 1;
            }
        }
        return ans;
    }
};