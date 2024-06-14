class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, -1)), atlantic(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    pacific[i][j] = 1;
                if (i == m-1 || j == n-1)
                    atlantic[i][j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == 1)
                    dfs(heights, i, j, m, n, pacific);
                if (atlantic[i][j] == 1)
                    dfs(heights, i, j, m, n, atlantic);
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                    result.push_back({i, j});
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, int r, int c, int& m, int& n, vector<vector<int>>& ocean) {
        int DIR[][2] = { {0,-1}, {1, 0}, {0, 1}, {-1, 0} }; // left, up, right, down

        for (int i = 0; i < 4; i++) {
            int nr = r + DIR[i][0], nc = c + DIR[i][1];
            // invalid index or visited
            if (nr < 0 || nc < 0 || nr >= m || nc >= n || ocean[nr][nc] == 1) 
                continue;

            if (heights[nr][nc] >= heights[r][c]) {
                ocean[nr][nc] = 1; // visited & can flow
                dfs(heights, nr, nc, m, n, ocean); 
            } 
        }
    }
};