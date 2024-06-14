class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pdt = 1;
        int right = 0;
        int left = 0;
        int n= nums.size();
        int ans = 0;
        for(right = 0; right < n; right++){
            pdt = pdt * nums[right];
            while(pdt >= k and left <= right){
                pdt /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};