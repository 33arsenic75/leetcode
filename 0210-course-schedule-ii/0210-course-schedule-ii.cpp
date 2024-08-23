class Solution {
public:
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
    //     int n = numCourses;
    //     vector<vector<int>>adj(n);
    //     vector<bool>vis(n,false);
    //     vector<int>indeg(n,0);
    //     for(vector<int>&v:prereq){
    //         indeg[v[0]]++;
    //         adj[v[1]].push_back(v[0]);
    //     }
    //     queue<int>q;
    //     for(int i = 0 ; i < n ; i++){
    //         if(indeg[i]==0)q.push(i);
    //     }
    //     vector<int>ans;
    //     while(!q.empty()){
    //         int at = q.front();
    //         q.pop();
    //         ans.push_back(at);
    //         vis[at]=true;
    //         for(int j:adj[at]){
    //             indeg[j]--;
    //             if(indeg[j]==0)q.push(j);
    //         }
    //     }
    //     if(ans.size()==n)return ans;
    //     return vector<int>();
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq){
        int n = numCourses;
        vector<int>f(n);
        vector<vector<int>>adj(n);
        for(vector<int>e:prereq){
            adj[e[1]].push_back(e[0]);
        }
        int key = n-1;
        vector<bool>vis(n);
        bool possible = true;
        function<void(int)>dfs = [&](int at){
            vis[at]=true;
            for(int to:adj[at]){
                if(!vis[to])dfs(to);
            }
            f[at]=key;
            key --;
        };
        for(int i = 0 ; i < n ; i++){
            if(!vis[i])dfs(i);
        }
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++)ans[f[i]]=i;
        for(vector<int>e:prereq){
            if(f[e[1]] > f[e[0]])return vector<int>();
        }
        return ans;
    }
};