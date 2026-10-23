class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int at = q.front();
            q.pop();

            for (int to : adj[at]) {
                if (!suspicious[to]) {
                    suspicious[to] = true;
                    q.push(to);
                }
            }
        }

        // If a non-suspicious method invokes a suspicious one,
        // we cannot remove any methods.
        for (auto& e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};