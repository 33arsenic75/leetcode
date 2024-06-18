class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(i<n){
            j = i;
            int setbit = __builtin_popcount(nums[i]);
            while(j < n && setbit == __builtin_popcount(nums[j]) )j++;
            sort(nums.begin() + i , nums.begin() + j);
            i = j;
        }
        return is_sorted(nums.begin(),nums.end());
    }
};