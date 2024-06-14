class Solution {
public:
    int n;
    int dx[3] = {-1, -1, -1};
    int dy[3] = {-1, 0, 1};

    bool inrange(int i, int j) {
        return (i >= 0) && (j >= 0) && (i < n) && (j < n);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ans = INT_MAX;  
                for (int k = 0; k < 3; k++) {
                    int prev_i = i + dx[k];
                    int prev_j = j + dy[k];
                    if (inrange(prev_i, prev_j)) {
                        ans = min(ans, matrix[i][j] + matrix[prev_i][prev_j]);
                    }
                }
                matrix[i][j] = ans;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
