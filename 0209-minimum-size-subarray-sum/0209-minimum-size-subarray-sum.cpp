class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n+1;
        int curr = 0;
        int sum = 0;
        int i = 0 , j = 0;
        while(i<n && j<n){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                ans = min(ans,j-i+1);
                i++;
            }
            j++;
        
        }
        if(ans == n+1)return 0;
        return ans;
    }
};