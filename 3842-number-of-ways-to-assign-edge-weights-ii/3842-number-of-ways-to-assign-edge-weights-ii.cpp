class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;

        // CSR adjacency
        vector<int> deg(n + 2, 0), adj(2 * (n - 1));
        for (auto& e : edges) { deg[e[0]]++; deg[e[1]]++; }
        for (int i = 1; i <= n + 1; i++) deg[i] += deg[i - 1];
        for (auto& e : edges) { adj[--deg[e[0]]] = e[1]; adj[--deg[e[1]]] = e[0]; }

        // Iterative preorder DFS: tin[v] = position, sp[pos] = depth of node at pos
        vector<int> tin(n + 1), depth(n + 1, 0), parent(n + 1, 0), st;
        st.reserve(n);
        st.push_back(1);
        int LOG = 32 - __builtin_clz(n);
        vector<int> sp(LOG * n);
        for (int t = 0; !st.empty(); t++) {
            int at = st.back(); st.pop_back();
            tin[at] = t;
            sp[t] = depth[at];
            for (int j = deg[at]; j < deg[at + 1]; j++) {
                int to = adj[j];
                if (to == parent[at]) continue;
                parent[to] = at;
                depth[to] = depth[at] + 1;
                st.push_back(to);
            }
        }

        // Sparse table of range-min depth over preorder
        for (int k = 1; k < LOG; k++) {
            int* prev = &sp[(k - 1) * n];
            int* cur = &sp[k * n];
            for (int i = 0; i + (1 << k) <= n; i++)
                cur[i] = min(prev[i], prev[i + (1 << (k - 1))]);
        }

        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++) pow2[i] = pow2[i - 1] * 2LL % MOD;

        vector<int> ans(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) { ans[i] = 0; continue; }
            int l = tin[u], r = tin[v];
            if (l > r) swap(l, r);
            // depth(lca) = min depth over preorder positions (l, r] minus 1
            l++;
            int k = 31 - __builtin_clz(r - l + 1);
            int lcaDepth = min(sp[k * n + l], sp[k * n + r - (1 << k) + 1]) - 1;
            int d = depth[u] + depth[v] - 2 * lcaDepth;
            ans[i] = pow2[d - 1];
        }
        return ans;
    }
};
