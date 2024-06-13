class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n = nums.size();
        // if(n==1)return;
        // int idx = n - 2;
        // for(; idx>0 ; idx--){
        //     if(nums[idx] < nums[idx+1])break;
        // }
        // // cout<<idx;
        // int idx2 = idx; int currmin = *max_element(nums.begin(),nums.end())+1;
        // for(int i = idx+1; i < n ; i++){
        //     if(nums[i]>nums[idx] && nums[i]<currmin){
        //         currmin = nums[i];
        //         idx2 = i;
        //     }
        // }
        // if(idx2==idx){
        //     reverse(nums.begin(),nums.end());
        //     return;
        // }
        // swap(nums[idx2],nums[idx]);
        // sort(nums.begin()+idx+1,nums.end());
        next_permutation(nums.begin(),nums.end());
        return;
    }
};