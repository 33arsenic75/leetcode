class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<long long> dis(n, LLONG_MAX);
        vector<int> numWays(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dis[0] = 0;
        numWays[0] = 1;
        pq.push({0, 0});
        
        int MOD = 1e9 + 7;
        
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dis[u]) continue;
            
            for (auto [v, w] : adj[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    numWays[v] = numWays[u];
                    pq.push({dis[v], v});
                } else if (dis[v] == dis[u] + w) {
                    numWays[v] = (numWays[v] + numWays[u]) % MOD;
                }
            }
        }
        
        return numWays[n - 1];
    }
};
