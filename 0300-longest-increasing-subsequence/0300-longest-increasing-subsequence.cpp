class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        int result = 0;
        for(int a: nums){
            int low = 1; 
            int high = n;
            int mid = 0;
            int ans = 0;

            while(low <= high){
                mid = low + (high - low)/2;
                if(dp[mid] < a){
                    ans = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            dp[ans+1] = a;
            result = max(result, ans + 1);
        }
        return result;
    }
};