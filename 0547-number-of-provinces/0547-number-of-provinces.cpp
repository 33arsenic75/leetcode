class Solution {
public:
    int n;
    vector<vector<int>>a;
    vector<bool>vis;
    int ans;
    void dfs(int i){
        if(vis[i])return;
        vis[i]=true;
        for(int j = 0; j < n ; j++){
            if(a[i][j] && !vis[j])dfs(j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        ans = 0;
        n = isConnected.size();
        a = isConnected;
        vis = vector<bool>(n,false);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;


    }
};