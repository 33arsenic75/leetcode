#include<numeric>

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int curr = 0;
        for(int i = 0 ; i < n ; i++){
            curr+=i*nums[i];
        }
        int ans = curr;
        for(int i = n-1 ; i>=0; i--){
            curr += sum - n*nums[i];
            ans = max(curr,ans);
        }
        return ans;
    }
};