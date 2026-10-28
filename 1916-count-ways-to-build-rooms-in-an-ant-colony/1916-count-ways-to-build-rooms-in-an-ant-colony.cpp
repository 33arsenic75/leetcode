class Solution {
public:
    static const int MOD = 1e9 + 7;

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[i].push_back(prevRoom[i]);
            adj[prevRoom[i]].push_back(i);
        }

        vector<int> sz(n, 1);

        function<void(int, int)> size = [&](int at, int par) {
            for (int to : adj[at]) {
                if (to == par) continue;
                size(to, at);
                sz[at] += sz[to];
            }
        };

        size(0, -1);

        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        auto power = [&](long long a, long long b) {
            long long res = 1;
            while (b) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        function<long long(int, int)> f = [&](int at, int par) -> long long {
            long long res = fact[sz[at] - 1];

            for (int to : adj[at]) {
                if (to == par) continue;

                res = res * f(to, at) % MOD;
                res = res * invFact[sz[to]] % MOD;
            }

            return res;
        };

        return f(0, -1);
    }
};