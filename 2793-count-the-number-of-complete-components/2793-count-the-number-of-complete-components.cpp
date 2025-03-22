class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);

        for(vector<int>&e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                queue<int>q;
                int nodes = 0, edges = 0;
                q.push(i);
                while(!q.empty()){
                    int at = q.front();
                    q.pop();
                    if(vis[at])continue;
                    vis[at]=true;
                    nodes += 1;
                    edges += adj[at].size();
                    for(int to: adj[at]){
                        q.push(to);
                    }
                }
                if(nodes*(nodes-1) == edges)ans++;
            }
        }    
        return ans;    
    }
};