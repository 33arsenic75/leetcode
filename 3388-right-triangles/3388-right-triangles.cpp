class Solution {
public:
    
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long n = grid.size(), m = grid[0].size();
        vector<int>down(n,0);
        vector<int>up(m,0);
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                down[i] += grid[i][j];
                up[j] += grid[i][j];
            }
        }

        long long total = 0;

        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                total += grid[i][j] * (down[i] - 1) * (up[j] - 1);
            }
        }
        return total;
    }
};