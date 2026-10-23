class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<long long> row_sums(n, 0);
        vector<long long> col_sums(m, 0);
        long long total_sum = 0;
        
        // Single pass to accumulate row sums, column sums, and total sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long val = grid[i][j];
                total_sum += val;
                row_sums[i] += val;
                col_sums[j] += val;
            }
        }
        
        // Check horizontal cuts using prefix of row sums
        long long current_row_sum = 0;
        for (int i = 0; i < n; i++) {
            current_row_sum += row_sums[i];
            if (current_row_sum * 2 == total_sum) {
                return true;
            }
        }
        
        // Check vertical cuts using prefix of column sums
        long long current_col_sum = 0;
        for (int j = 0; j < m; j++) {
            current_col_sum += col_sums[j];
            if (current_col_sum * 2 == total_sum) {
                return true;
            }
        }
        
        return false;
    }
};