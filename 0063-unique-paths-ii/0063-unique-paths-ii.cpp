class Solution {
public:
    int n,m;
    vector<vector<int>>ans;
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        ans = vector<vector<int>>(n,vector<int>(m,0));
        ans[0][0]=1-g[0][0];
        for(int i = 1; i < m ; i++){
            ans[0][i] = ans[0][i-1]*(1-g[0][i]);
        }
        for(int i = 1; i < n ; i++){
            ans[i][0] = ans[i-1][0]*(1-g[i][0]);
        }
        for(int i = 1; i < n ; i ++){
            for(int j = 1; j < m ; j++){
                ans[i][j] = (ans[i-1][j] + ans[i][j-1])*(1-g[i][j]);                
            }
        }
        return ans[n-1][m-1];
    }
};