class Solution {
public:
    const int mod = 1e9+7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // Adjacency list
        vector<vector<vector<int>>> adj(n+1);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }

        // Dijkstra's Algorithm
        vector<int> dist(n+1, INT_MAX);
        vector<bool> vis(n+1, false);
        dist[n] = 0;
        set<pair<int, int>> st;
        st.insert({0, n});

        while(!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());
            if(vis[u]) continue;
            vis[u] = true;

            for(auto& edge : adj[u]) {
                int weight = edge[0], v = edge[1];
                if(d + weight < dist[v]) {
                    dist[v] = d + weight;
                    st.insert({dist[v], v});
                }
            }
        }

        // // Debugging: Print distances
        // for(int i = 1; i <= n; i++) {
        //     cout << i<<" "<<dist[i] << "\n";
        // }
        // Dynamic Programming on Restricted Paths
        vector<int> ans(n+1, 0);
        ans[n] = 1;
        st.clear();

        for(int i = 1; i <= n; i++) {
            st.insert({dist[i], i});
        }

        while(!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());
            // cout<<u<<"\n";
            for(auto& edge : adj[u]) {
                int v = edge[1];
                if(dist[v] > dist[u]) {
                    ans[v] = (ans[v] + ans[u]) % mod;
                }
            }
        }

        return ans[1];
    }
};
