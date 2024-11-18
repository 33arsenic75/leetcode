class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        bool result = true;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==j)result&=(grid[i][j]!=0);
                else if(i+j==n-1)result&=(grid[i][j]!=0);
                else result&=(grid[i][j]==0);
            }
        }
        return result;
    }
};