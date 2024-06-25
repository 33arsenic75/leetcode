class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long n = nums.size();
        long long add = nums[0], sub = nums[0];
        for(long long i = 1; i < n ; i++){
            long long tadd = max(add,sub)+nums[i];
            long long tsub = add - nums[i];
            add = tadd, sub = tsub;
        }
        return max(add,sub);
    }
};