class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(vector<int>v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int component = 0;
        function<int(int,int)>dfs = [&](int at, int p){
            int sum = values[at]%k;
            for(int to: adj[at]){
                if(to == p)continue;
                sum += dfs(to,at);
            }
            if(sum%k==0){
                component++;
                return 0;
            }
            return sum%k;
        };
        dfs(0,-1);
        return component;
    }
};