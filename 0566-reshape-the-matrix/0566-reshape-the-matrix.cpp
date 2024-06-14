class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size())return mat;
        vector<vector<int>>ans(r,vector<int>(c,0));
        int m = mat.size();
        int n = mat[0].size();
        int curr = 0; int x,y;
        for(int i = 0; i<r; i++){
            for(int j = 0 ; j<c ; j++){
                x = curr / n;
                y = curr % n;
                ans[i][j] = mat[x][y];
                curr++;
            }
        }
        return ans;
    }
};