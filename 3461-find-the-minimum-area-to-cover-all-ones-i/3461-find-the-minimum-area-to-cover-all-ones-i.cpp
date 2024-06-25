class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fx=n,lx=0,fy=m,ly=0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j]==1){
                    fx = min(fx,i);lx = max(lx,i);
                    fy = min(fy,j);ly = max(ly,j);
                }
            }
        }
        return (lx-fx+1)*(ly-fy+1);
    }
};