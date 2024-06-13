class Solution {
public:
    void bt(int n,vector<bool>&vis,vector<vector<int>>&ans,vector<int>&p,vector<int>&nums){
        if(p.size()==n){
            ans.push_back(p);
            return;
        }
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                p.push_back(nums[i]);
                bt(n,vis,ans,p,nums);
                p.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        vector<int>p;
        bt(n,vis,ans,p,nums);
        return ans;
    }
};