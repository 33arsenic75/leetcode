class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> memo(n, vector<int>(m, 1e9));
        memo[n - 1][m - 1] = A[n - 1][m - 1] < 0 ? -A[n - 1][m - 1] + 1 : 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i < n - 1)
                    memo[i][j] = min(memo[i][j], max(1, memo[i + 1][j] - A[i][j]));
                if(j < m - 1)
                    memo[i][j] = min(memo[i][j], max(1, memo[i][j + 1] - A[i][j]));
            }
        }
        return memo[0][0];
    }
};