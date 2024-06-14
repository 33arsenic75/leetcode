class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n = numCourses;
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(vector<int>&v:prereq){
            indeg[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(indeg[i]==0)q.push(i);
            // cout<<i<<' ';
            // for(int j:adj[i])cout<<j<<' ';
            // cout<<'\n';
        }
        while(!q.empty()){
            int at = q.front();
            // cout<<at<<'\n';
            q.pop();
            for(int j:adj[at]){
                indeg[j]--;
                if(indeg[j]==0)q.push(j);
            }
            vis[at]=true;
        }
        return (count(vis.begin(),vis.end(),true)==n);
    }
};