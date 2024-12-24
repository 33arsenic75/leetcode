class Solution {
public:
    int dp(vector<vector<int>>&e){
        int n = e.size()+1;
        vector<vector<int>>adj(n);
        for(vector<int>ee:e){
            adj[ee[0]].push_back(ee[1]);
            adj[ee[1]].push_back(ee[0]);
        }
        vector<int>d1(n),d2(n);
        function<void(int,int)>dfs1 = [&](int at,int p){
            for(int to:adj[at]){
                if(to == p)continue;
                d1[to] = 1 + d1[at];
                dfs1(to,at);
            }
        };
        function<void(int,int)>dfs2 = [&](int at,int p){
            for(int to:adj[at]){
                if(to == p)continue;
                d2[to] = 1 + d2[at];
                dfs2(to,at);
            }
        };
        dfs1(0,-1);
        int mx = 0, mxidx = 0;
        for(int i = 0 ; i < n ; i++){
            if(d1[i]>mx){
                mx = d1[i];
                mxidx = i;
            }
        }
        dfs2(mxidx,-1);
        for(int i = 0 ; i < n ; i++){
            mx = max(mx,d2[i]);
        }
        return mx;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int d1 = dp(e1);
        int d2 = dp(e2);
        int ans1 = (d1+1)/2 + (d2+1)/2 + 1;
        return max(max(d1,d2),ans1);
    }
};