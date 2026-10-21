class Solution {
public:
    int solve(int i,int c,int &a,int &b,vector<vector<int>> &dp,vector<int> &v1,vector<int> &v2){
        if(i==a){
            return 0;
        }
        if(dp[i][c] != -1)return dp[i][c];
        int p = (c==b) ? (i==0 ? -1 : v1[i-1]) : v2[c];
        int j = upper_bound(v2.begin(),v2.end(),p)-v2.begin();
        int take = 2001,nottake = 2001;
        if(j!=b)
        take = solve(i+1,j,a,b,dp,v1,v2)+1;
        if(v1[i]>p)
        nottake = solve(i+1,b,a,b,dp,v1,v2);
        return dp[i][c] = min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        sort(arr2.begin(),arr2.end());
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int a= solve(0,m,n,m,dp,arr1,arr2);
        if(a>n)return -1;
        return a;
    }
};