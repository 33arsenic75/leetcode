class Solution {
public:
    int n; vector<int> dp;
    int rec(int i, vector<int> &a1, vector<int> &a2){
        if (i==n-1) return 0;
        int &ans = dp[i];
        if (ans != -1) return ans;
        ans = 1e8;
        if (a1[i] <= a1[n-1] and a2[i] <= a2[n-1]) ans = rec(i+1, a1, a2);
        if (a2[i] <= a1[n-1] and a1[i] <= a2[n-1])
            ans = min(ans, 1+rec(i+1, a1, a2));
        return ans;
    }


    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp.assign(n+1, -1);
        int ans = rec(0,nums1,nums2);
        swap(nums1[n-1], nums2[n-1]);
        dp.assign(n+1, -1);
        ans = min(ans, 1+rec(0,nums1,nums2));
        return (ans >= 1e8 ? -1 : ans);
    }
};