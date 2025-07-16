class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)nums[i] %= 2;
        int o = count(nums.begin(), nums.end(), 1);
        int z = count(nums.begin(), nums.end(), 0);
        int last = 1 - nums[0];
        int len = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == last){
                len++;
                last = 1 - last;
            }
        }
        return max(len, max(z, o));
    }
};