class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int dx[3] = {-1,0,1};
        function<int(int,int,int)>f = [&](int d,int i,int j){
            if(i<0 || j<0 || i>= m || j>= m)return 0;
            else if(d<0 || d>= n)return 0;
            else if(dp[d][i][j]!=-1)return dp[d][i][j];
            int best = 0;
            for(int x1: dx){
                for(int x2: dx){
                    best = max(best,f(d+1,i+x1,j+x2));
                }
            }
            if(i!=j)dp[d][i][j] = grid[d][i] + grid[d][j] + best;
            else dp[d][i][j] = grid[d][i] + best;
            return dp[d][i][j];
        };
        int ans = f(0,0,m-1);
        return ans;
    }
};