class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool>exist(n+1,false);
        for(int i:nums)exist[i]=true;
        vector<int>ans;
        for(int i=1;i<=n;i++){
            if(!exist[i])ans.push_back(i);
        }
        return ans;
    }
};