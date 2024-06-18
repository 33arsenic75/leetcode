class Solution {
public:
    const long long MOD = 1000'000'007;
    long long pow(long long p){
        if(p==0)return 1;
        long long ans = pow(p/2);
        ans *= ans;
        ans %= MOD;
        if(p%2==1)ans *= 2;
        ans%=MOD;
        return ans;
    };
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        long long q = queries.size();
        vector<long long>powers;
        for(long long i = 0 ; i < 32 ; i ++){
            if((n>>i)&1)powers.push_back(i);
        }
        long long sz = powers.size();
        // for(long long i:powers)cout<<i<<" ";
        // cout<<"\n";
        for(long long i = 1 ; i < sz ; i++)powers[i]+=powers[i-1];
        vector<int>ans(q);
        // for(long long i:powers)cout<<i<<" ";
        for(long long i = 0 ; i < q ; i++){
            long long l = queries[i][0], r = queries[i][1];
            if(r >= powers.size())r = powers.size() - 1;
            ans[i] += powers[r];
            if(l!=0)ans[i] -= powers[l-1];
        }
        for(int&i:ans)i = pow(i);
        return ans;
    }
};