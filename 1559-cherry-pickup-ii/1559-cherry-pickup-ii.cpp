class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m,INT_MIN)));
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
        for(int i = 1 ; i < n ; i++){
            for(int p1 = 0 ; p1 < m ; p1++){
                for(int p2 = 0 ; p2 < m ; p2++){
                    int best = INT_MIN;
                    for(int p1old = max(0,p1-1) ; p1old < min(m, p1+2) ; p1old++){
                        for(int p2old = max(0,p2-1) ; p2old < min(m, p2+2) ; p2old++){
                            best = max(best, dp[i-1][p1old][p2old]);
                        }
                    }
                    if(best!=INT_MIN && p1!=p2)dp[i][p1][p2]=best+grid[i][p1]+grid[i][p2];
                    else if(best!=INT_MIN)dp[i][p1][p2]=best+grid[i][p1];
                }
            }
        }
        int ans = 0;
        for(int p1 = 0 ; p1 < m ; p1++){
            for(int p2 = 0 ; p2 < m ; p2++)ans=max(ans, dp[n-1][p1][p2]);
        }
        return ans;
    }
};