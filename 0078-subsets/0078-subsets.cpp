class Solution {
public:
    void bt(vector<int>& nums, vector<int> temp , int i,vector<vector<int>> &ans) {
        if(i >= nums.size()){
            ans.push_back(temp);
            return ;
        }
        bt(nums,temp,i+1, ans);
        int num = nums[i];
        temp.push_back(num);
        bt(nums,temp,i+1,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        bt(nums,temp,i,ans);
        return ans;
    }
};