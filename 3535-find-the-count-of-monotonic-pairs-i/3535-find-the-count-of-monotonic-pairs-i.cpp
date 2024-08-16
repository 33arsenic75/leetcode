using ll = long long;
const ll mod = 1000'000'007;
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        ll n = nums.size();
        vector<vector<ll>>dp(n,vector<ll>(1001));
        for(ll i = 0 ; i <= nums[0] ; i ++)dp[0][i]=1;
        for(ll i = 1 ; i < n ; i++){
            for(ll j = 0 ; j <= nums[i] ; j++){
                ll other = nums[i]-j;
                for(ll k = 0 ; k <= j ; k++){
                    ll other2 = nums[i-1]-k;
                    if(other2>=other){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        ll ans = 0;
        for(ll i = 0 ; i <= nums[n-1] ; i++){
            ans += dp[n-1][i];
            ans%=mod;
        }
        return ans;        
    }
};