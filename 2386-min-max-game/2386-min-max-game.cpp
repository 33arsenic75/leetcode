class Solution {
public:
    int minMaxGame(vector<int>&nums,int n){
        if(n==1)return nums[0];
        for(int i = 0 ; i < n/2 ; i++){
            if(i%2){
                nums[i] = max(nums[2*i],nums[2*i+1]);
            }
            else{
                nums[i] = min(nums[2*i],nums[2*i+1]);
            }
        }
        return minMaxGame(nums,n/2);
    }
    int minMaxGame(vector<int>& nums) {
        return minMaxGame(nums,nums.size());
    }
};