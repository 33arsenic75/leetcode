class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        vector<int>indeg(n,0);
        for(vector<int>&v:prereq){
            indeg[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int at = q.front();
            q.pop();
            ans.push_back(at);
            vis[at]=true;
            for(int j:adj[at]){
                indeg[j]--;
                if(indeg[j]==0)q.push(j);
            }
        }
        if(ans.size()==n)return ans;
        return vector<int>();
    }
};