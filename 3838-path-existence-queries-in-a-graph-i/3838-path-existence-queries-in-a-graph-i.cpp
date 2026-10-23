class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>max_idx(n, n-1);
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i+1] - nums[i] <= maxDiff){
                max_idx[i] = max_idx[i+1];
            }
            else max_idx[i] = i;
        }
        int q = queries.size();
        int u, v;
        vector<bool>ans(q);
        #pragma unroll
        for(int i = 0 ; i < q ; i++){
            u = queries[i][0];
            v = queries[i][1];
            if(u>v)swap(u, v);
            ans[i] = (max_idx[u] >= v);
        }
        return ans;
    }
};