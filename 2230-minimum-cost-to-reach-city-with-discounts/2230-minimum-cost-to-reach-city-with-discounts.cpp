class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : highways) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<long long>> dist(
            n, vector<long long>(discounts + 1, LLONG_MAX)
        );

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, u, used] = pq.top();
            pq.pop();

            if (d != dist[u][used]) continue;

            if (u == n - 1) return (int)d;

            for (auto [v, w] : adj[u]) {
                // Traverse without a discount
                if (d + w < dist[v][used]) {
                    dist[v][used] = d + w;
                    pq.push({d + w, v, used});
                }

                // Traverse with a discount
                if (used < discounts) {
                    long long nd = d + w / 2;
                    if (nd < dist[v][used + 1]) {
                        dist[v][used + 1] = nd;
                        pq.push({nd, v, used + 1});
                    }
                }
            }
        }

        return -1;
    }
};