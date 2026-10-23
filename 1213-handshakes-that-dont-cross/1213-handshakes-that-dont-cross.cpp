
typedef long long ll;
const ll MOD = 1000000007;

class Solution {
public:
    ll modpow(ll base, ll exp) {
        ll res = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }

        return res;
    }

    int numberOfWays(int numPeople) {
        int n = numPeople / 2;

        ll num = 1;
        ll den = 1;

        for (int i = n + 2; i <= 2 * n; i++) {
            num = num * i % MOD;
        }

        for (int i = 1; i <= n; i++) {
            den = den * i % MOD;
        }

        ll ans = num * modpow(den, MOD - 2) % MOD;
        return ans;
    }
};
