class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k){
            int mn = *min_element(nums.begin(),nums.end());
            // cout<<mn<<" "<<'\n';
            for(int i = 0 ; i < n ; i++){
                if(mn == nums[i]){
                    nums[i] *= multiplier;
                    break;
                }
            }
            k--;
        }
        return nums;
    }
};