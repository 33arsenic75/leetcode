class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);

        for (vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(0);

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!q.empty()) {
            int at = q.front();
            q.pop();

            for (int to : adj[at]) {
                if (dist[to] != INT_MAX) continue;
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            int d = dist[i];
            int roundTrip = 2 * d;
            int lastSent = ((roundTrip - 1) / patience[i]) * patience[i];

            ans = max(ans, lastSent + roundTrip);
        }

        return ans + 1;
    }
};
/// server i recieves message at 2d time.
/// sends at patience[i] = p.
/// p*k < 2d
/// pk + 2d == floor(2d/p)*p + 2d
/// (2d-1)/p * p + 2d
/// 3/2 * 2 + 4 = 6
