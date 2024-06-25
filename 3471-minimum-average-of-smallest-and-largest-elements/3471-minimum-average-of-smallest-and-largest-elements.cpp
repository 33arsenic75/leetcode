class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        double ans = nums[0] + nums[n-1];
        int l = 0, r = n-1;
        while(l<r){
            if(nums[l]+nums[r]<ans)ans = nums[l]+nums[r];
            l++,r--;
        }
        return ans/2;
    }
};