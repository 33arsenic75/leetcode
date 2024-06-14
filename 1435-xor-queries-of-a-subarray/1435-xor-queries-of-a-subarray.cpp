class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i = 1 ; i < n ; i++)arr[i] = arr[i-1]^arr[i];
        int q = queries.size();
        vector<int>ans(q,0);
        int l,r;
        for(int i = 0 ; i < q ; i++){
            l = queries[i][0];
            r = queries[i][1];
            if(l!=0)ans[i] = arr[l-1]^arr[r];
            else ans[i] = arr[r];
        }
        return ans;
    }
};