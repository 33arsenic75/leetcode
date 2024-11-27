class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < n - 1 ; i++){
            adj[i].push_back(i+1);
        }
        auto bfs=[&](vector<vector<int>>&a){
            vector<int>depth(n,n);
            vector<bool>vis(n,false);
            depth[0]=0;
            queue<int>q;q.push(0);
            while(!q.empty()){
                int at = q.front();
                q.pop();
                if(vis[at])continue;
                vis[at]=true;
                for(int to:adj[at]){
                    depth[to]=min(depth[to],1+depth[at]);
                    q.push(to);
                }
            }
            return depth[n-1];
        };
        vector<int>ans;
        for(vector<int>v:queries){
            adj[v[0]].push_back(v[1]);
            ans.push_back(bfs(adj));
        }
        return ans;
    }
};