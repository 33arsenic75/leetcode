class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int>dp;
    int f(int idx){
        if(idx<0 || idx>= dp.size())return 0;
        return dp[idx]%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high+1,0);
        dp[0]=1;
        int ans = 0;
        for(int i = 1 ; i <= high ; i++){
            dp[i] = ( f(i-zero) + f(i-one) )%mod;
            if(i>=low){
                ans += dp[i];
                ans %= mod;
            }
            // cout<<i<<" "<<dp[i]<<"\n";
        }
        return ans;
    }
};