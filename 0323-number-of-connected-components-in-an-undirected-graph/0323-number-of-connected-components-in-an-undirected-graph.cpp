class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n, false);
        vector<vector<int>>adj(n);
        for(vector<int>&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<void(int,int)>dfs = [&](int u, int p){
            if(vis[u])return;
            vis[u]=true;
            for(int to: adj[u]){
                if(to == p)continue;
                dfs(to, u);
            }
        };
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            if(!vis[i]){
                ans++;
                dfs(i, -1);
            }
        }
        return ans;
    }
};