using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& wts, int k) {
        int n = wts.size();
        vector<ll>ans(n-1);
        for(int i = 1 ; i < n ; i++){
            ans[i-1] = (ll)wts[i-1] + (ll)wts[i]; 
        }
        sort(ans.begin(), ans.end());
        // for(int i = 0 ; i < n - 1; i++)cout<<ans[i]<<" ";
        ll mx = 0, mn = 0;
        for(int i = 0 ; i < k-1 ; i++){
            mn += ans[i];
            mx += ans[n-2-i];
        }
        return mx - mn;
    }
};