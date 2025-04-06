class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(n);
        ans[n-1] = 1;
        int idx = n-1;
        int return_val = 1;
        for(int i = n-2 ; i >= 0 ; i--){
            int best = 0;
            for(int j = i+1 ; j < n ; j ++){
                if(nums[j]%nums[i] == 0)best = max(best,ans[j]);
            }
            ans[i] = 1 + best;
            if(ans[i] > return_val){
                return_val = ans[i];
                idx = i;
            }
        }
        for(int i = 0 ; i < n ; i++){
            cout<<nums[i]<<" "<<ans[i]<<"\n";
        }
        vector<int>x = {nums[idx]};
        int last = idx;
        for(int i = idx + 1 ; i < n ; i++){
            if((ans[i] == ans[last] - 1) && (nums[i]%nums[last] == 0)){
                x.push_back(nums[i]);
                last = i;
            }
        }
        return x;
    }
};