class Solution {
public:
    int solve(int cnt,int curr,vector<int>& nums,vector<vector<int>>&dp){
        if(cnt==0 && curr==0) return 1;
        else if(cnt==0) return 0;
        if(dp[cnt][curr+1]!=-1)return dp[cnt][curr+1];
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(cnt==3)sum+=solve(cnt-1,nums[i],nums,dp);
            else sum+=solve(cnt-1,curr&nums[i],nums,dp);
        }
        return dp[cnt][curr+1]=sum;
    }
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(4,vector<int>(1e6,-1));
        int ans=solve(3,-1,nums,dp);
        return ans;
    }
};