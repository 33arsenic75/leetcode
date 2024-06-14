class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(vector<int>&v:edges){
            adj[v[1]].push_back(v[0]);
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            if(adj[i].size()==0)ans.push_back(i);
        }
        if(ans.size()!=1)return -1;
        else return ans[0];
    }
};