#pragma GCC optimize("O3", "unroll-loops")
const int mod=1e9+7; // This is a prime number
class Solution {
public:
    vector<int> fact;
    void factorialMod(int n){
        fact.assign(n+1, 1);
        for(int i=2; i<=n; i++){
            fact[i]=(long long)fact[i-1]*i%mod;
        }
    }
    // Find x, y, d such that ax + by = d where d = gcd(a, b)
    int modInverse(int a, int b=mod) {
        int x0 = 1, x1 = 0;
        int r0 = a, r1 = b;
        while (r1 != 0) {
            int q = r0/r1, rr = r1, xx = x1;
            r1 = r0-q * r1;
            x1 = x0-q * x1;
            r0 = rr;
            x0 = xx;
        }
        if (x0 < 0) x0+= b;
        return x0;
    }
    
    long long powMod(long long x, int n){
      if (n==0) return 1;
      int y=(n&1)?x:1;
      return powMod((long long)x*x%mod, n/2)*y%mod;
    }

    long long twoPowMod(int n){
        if (n<30) return 1<<n;
        auto [q, r]=div(n, 30);
        long long y=(1<<r), B=(1<<30)%mod;
        return powMod(B, q)*y%mod;
    }


    int numberOfSequence(int n, vector<int>& sick) {
        int m=sick.size();
        factorialMod(n-m);
        long long ans=fact[n-m];
        int total=0;
        if (sick[0] != 0) {
            total=sick[0]; 
            ans=ans*modInverse(fact[total])%mod; 
        }
        for(int i=1; i<m; i++){
            int len=sick[i]-sick[i-1]-1;
            if (len==0) continue;
            total+=len;
            ans=ans*modInverse(fact[len])%mod;
            ans=ans*twoPowMod(len-1)%mod;
        //    cout<<"len="<<len<<endl;
        }
        if (sick.back()!=n-1) {
            int len=n-1-sick.back();
            ans=ans*modInverse(fact[len])%mod;
        }
        return ans%mod;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();