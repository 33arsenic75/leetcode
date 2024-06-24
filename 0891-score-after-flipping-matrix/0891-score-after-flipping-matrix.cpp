class Solution {
public:
    vector<vector<int>>grid;
    int n,m;
    void fliprow(int i){
        for(int j = 0; j < m ; j++)grid[i][j] = 1 - grid[i][j];
    }   
    void flipcol(int i){
        for(int j = 0 ; j < n ; j++)grid[j][i] = 1 - grid[j][i];
    }
    int matrixScore(vector<vector<int>>& grd) {
        this->grid = grd;
        n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0]==0)fliprow(i);
        }
        // for(int i = 0 ; i < n ; i++){
            // for(int j = 0 ; j < m ; j ++)cout<<grid[i][j]<<" ";
            // cout<<'\n';
        // }
        for(int j = 1; j < m ; j++){
            int cnt = 0;
            for(int i = 0 ; i < n ; i++)cnt += grid[i][j];
            if(cnt*2<n){
                flipcol(j);
            }
        }
        // for(int i = 0 ; i < n ; i++){
            // for(int j = 0 ; j < m ; j ++)cout<<grid[i][j]<<" ";
            // cout<<'\n';
        // }
        int ans = 0;
        for(int i = 0 ; i < n ;i ++){
            for(int j = 0 ; j < m ; j++){
                if( grid[i][j] == 1)ans += (1<<(m-1-j));
            }
        }
        return ans;
    }
};