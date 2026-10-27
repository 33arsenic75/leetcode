class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);

        for (vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<double(int, int, int)> f = [&](int at, int par, int t) -> double {
            if (t == 0) {
                return (double)(at == target);
            }

            int num_children = adj[at].size();
            num_children -= (int)(par != 0);

            if (num_children == 0) {
                return (double)(at == target);
            }

            double ans = 0;

            for (int to : adj[at]) {
                if (to == par) continue;
                ans += f(to, at, t - 1);
            }

            ans /= num_children;
            return ans;
        };

        return f(1, 0, t);
    }
};