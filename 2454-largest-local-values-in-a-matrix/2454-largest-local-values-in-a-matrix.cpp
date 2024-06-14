class Solution {
public:
    vector<vector<int>>grd;
    int help(int i, int j){
        int ans = grd[i][j];
        for(int k = i-1; k < i+2 ; k++){
            for(int l = j-1 ; l < j+2 ; l++){
                ans = max(ans,grd[k][l]);
            }
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        grd = grid;
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        for(int i = 0 ; i < n-2 ; i++){
            for(int j = 0 ; j < n-2; j++){
                ans[i][j] = help(i+1,j+1);
            }
        }
        return ans;
    }
};