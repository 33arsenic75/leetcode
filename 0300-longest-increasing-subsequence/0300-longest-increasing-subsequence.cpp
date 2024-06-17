class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /// DP1
        // int n = nums.size();
        // vector<int>ans(n,1);
        // for(int i = 0 ; i < n ; i++){
            // for(int j = 0 ; j < i ; j++){
                // if(nums[j] < nums[i]){
                    // ans[i] = max(ans[i],ans[j]+1);
                // }
            // }
        // }
        // return *max_element(ans.begin(),ans.end());

        /// DP2
        // int n = nums.size();
        // const int INF = 1e9;
        // vector<int>d(n+1,INF);
        // d[0] = -INF;
        // for(int i: nums){
            // for(int pos = 1 ; pos <= n ; pos++){
                // if(d[pos-1] < i){
                    // d[pos] = min(d[pos],i);
                // }
            // }
        // }
        // int ans = 0;
        // for(int i = 0 ; i <= n ; i++){
            // if(d[i]!=INF)ans = i;
        // }
        // return ans;

        /// nlog(n)
        int n = nums.size();
        const int INF = 1e9;
        vector<int>d(n+1,INF);
        d[0] = -INF;
        for(int i: nums){
            int low = 0, high = n, mid , ans = 0;
            while(low<=high){
                mid = low + (high-low)/2;
                if(d[mid] >= i){
                    ans = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            d[ans] = i;
        }
        int ans = 0;
        for(int i = 0 ; i <= n ; i++){
            if(d[i]!=INF)ans = i;
        }
        return ans;
    }
};