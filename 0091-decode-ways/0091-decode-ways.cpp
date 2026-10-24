class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[n-1] = isvalid(s, n-1, 1) ? 1 : 0;
        if(n==1)return dp[n-1];
        dp[n-2] = isvalid(s, n-2, 1) ? dp[n-1]: 0;
        dp[n-2] += isvalid(s, n-2, 2) ? 1 : 0;
        for(int i = n-3 ; i >= 0 ; i--){
            if(isvalid(s, i, 1))dp[i] += dp[i+1];
            if(isvalid(s, i, 2))dp[i] += dp[i+2];
        }

        // for(int i = 0 ; i < n ; i++)cout<<dp[i]<<' ';
    
        return dp[0];
    }
    bool isvalid(string&s, int i, int sz){
        int val = stoi(s.substr(i, sz));
        return (val <= 26) && (val>=0) && (s[i]!='0');
    }
};

