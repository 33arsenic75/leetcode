class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1, false);
        dp[n]=true;
        for(int i = n-1 ; i >= 0; i--){
            for(string&word: wordDict){
                if(
                    (s.substr(i, word.size()) == word) &&
                    dp[(i + word.size())]
                ){
                    dp[i]=true;
                }
            }
        }
        return dp[0];
    }
};