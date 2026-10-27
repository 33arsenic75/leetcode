class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        for (int i = 0; i < n; i++) ans[0][i] = '.';
        for (int i = 0; i < m; i++) ans[i][n - 1] = '.';

        return ans;
    }
};