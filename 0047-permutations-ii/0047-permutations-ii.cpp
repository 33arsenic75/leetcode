class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp = nums;
        ans.push_back(temp);
        while(next_permutation(nums.begin(),nums.end())){
            temp = nums;
            ans.push_back(temp);
        }
        return ans;
    }
};