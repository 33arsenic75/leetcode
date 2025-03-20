class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<vector<int>>> adj(n);
        for (vector<int>& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> component(n, 0);
        vector<int> bitwiseand(n, -1);
        vector<bool> vis(n, false);
        int head = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                int andd = INT_MAX;
                while (!q.empty()) {
                    int at = q.front();
                    q.pop();
                    component[at] = i;
                    if (vis[at]) continue;
                    vis[at] = true;
                    for (vector<int>& e : adj[at]) { 
                        andd &= e[1];
                        q.push(e[0]);
                    }
                }
                bitwiseand[i] = andd;
            }
        }
        // for(int i = 0 ; i < n ; i++){
        //     cout<<component[i]<<" "<<bitwiseand[i]<<"\n";
        // }
        int qsize = query.size();
        vector<int> ans(qsize, 0);
        for (int i = 0; i < qsize; i++) {
            // cout<<query[i][0]<<" "<<query[i][1]<<"\n";
            if (component[query[i][0]] == component[query[i][1]]) {
                ans[i] = bitwiseand[component[query[i][0]]];
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
