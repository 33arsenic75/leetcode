class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> island_idx(n, vector<int>(m, 0));

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        vector<int> sum_idx(1, 0);
        vector<int> st;
        st.reserve(n * m);

        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 || island_idx[i][j] != 0)
                    continue;

                idx++;
                sum_idx.push_back(0);

                island_idx[i][j] = idx;
                st.push_back(i * m + j);

                while (!st.empty()) {
                    int cur = st.back();
                    st.pop_back();

                    int x = cur / m;
                    int y = cur % m;

                    sum_idx[idx] = (sum_idx[idx] + grid[x][y] % k) % k;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (grid[nx][ny] == 0 || island_idx[nx][ny] != 0)
                            continue;

                        island_idx[nx][ny] = idx;
                        st.push_back(nx * m + ny);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= idx; i++)
            ans += (sum_idx[i] == 0);

        return ans;
    }
};