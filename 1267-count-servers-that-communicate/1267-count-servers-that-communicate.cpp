class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>row(n, 0);
        vector<int>col(m, 0);
        for(int i = 0 ; i < n ; i++){
            row[i] = grid[i][0];
            for(int j = 1 ; j < m ; j++)row[i] += grid[i][j];
        }

        for(int j = 0 ; j < m ; j++){
            col[j] = grid[0][j];
            for(int i = 1 ; i < n ; i++)col[j] += grid[i][j];
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans += grid[i][j] * (int)((row[i] > 1) ||  (col[j] > 1));
            }
        }
        return ans;
    }
};