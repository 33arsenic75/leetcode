class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0);
        unordered_set<long long> adj;
        adj.reserve(2 * edges.size());

        auto encode = [&](int u, int v) -> long long {
            if (u > v) swap(u, v);
            return 1LL * u * (n + 1) + v;
        };

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            degree[u]++;
            degree[v]++;
            adj.insert(encode(u, v));
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (degree[i] & 1) odd.push_back(i);
        }

        int cnt = odd.size();

        if (cnt == 0) return true;
        if (cnt != 2 && cnt != 4) return false;

        auto connected = [&](int u, int v) {
            return adj.count(encode(u, v));
        };

        if (cnt == 2) {
            int u = odd[0], v = odd[1];

            if (!connected(u, v)) return true;

            for (int i = 1; i <= n; i++) {
                if (i == u || i == v) continue;
                if (!connected(u, i) && !connected(v, i))
                    return true;
            }

            return false;
        }

        int a = odd[0], b = odd[1];
        int c = odd[2], d = odd[3];

        return (!connected(a, b) && !connected(c, d)) ||
               (!connected(a, c) && !connected(b, d)) ||
               (!connected(a, d) && !connected(b, c));
    }
};