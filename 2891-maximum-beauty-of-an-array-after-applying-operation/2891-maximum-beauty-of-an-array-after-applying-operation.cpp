class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
            int low = i, high = n-1 , mid = 0, ans = i;
            while(low<=high){
                mid = low + (high-low)/2;
                if(nums[mid]-nums[i]<=2*k){
                    ans = mid; 
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            result = max(result,ans-i+1);
        }
        return result;
    }
};