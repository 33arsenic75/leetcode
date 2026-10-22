class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n, 0);
        map<int,int>count;
        for(int i = n-2-k ; i >= 0 ; i--){
            count[nums[i+k+1]]++;
            ans[i] = count[nums[i]];
        }
        return ans;
    }
};