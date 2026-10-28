class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans = INT_MAX;
        vector<vector<int>>adj(n+1);
        for(vector<int>&e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int at = 1 ; at <= n ; at++){
            vector<bool>vis(n+1, false);
            for(int d1 : adj[at]){
                vis[d1]=true;
                for(int d2: adj[d1]){
                    if(vis[d2]){
                        int degree = adj[at].size() + adj[d1].size() + adj[d2].size() - 6;
                        ans = min(ans, degree);
                    }
                }
            }
        }



        return ans == INT_MAX ? -1 : ans;
    }
};