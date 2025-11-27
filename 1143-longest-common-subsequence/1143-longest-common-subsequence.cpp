class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n, vector<int>(m, 0));

        function<int(int,int)>memo = [&](int i, int j){
            if(i>=0 & i<n & j>=0 & j<m){
                return dp[i][j];
            }
            return 0;
        };
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dp[i][j] = max(memo(i-1,j), memo(i, j-1));
                if(s1[i] == s2[j]){
                    dp[i][j] = max(dp[i][j], 1 + memo(i-1,j-1));
                }
            }
        }
        return memo(n-1,m-1);
    }
};