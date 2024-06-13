class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>a(n,vector<int>(m,1));
        for(int i = 1 ; i < n ; i++){
            for(int j = 1; j < m; j++){
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[n-1][m-1];
        // if(n==1 || m==1)return 1;
        // return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};