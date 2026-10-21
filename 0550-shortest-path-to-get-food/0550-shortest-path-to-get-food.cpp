class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> q;
        q.reserve(n * m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    q.push_back(i * m + j);
                    grid[i][j] = 'X';
                }
            }
        }

        int head = 0, dist = 0;

        while (head < (int)q.size()) {
            int end = q.size();

            while (head < end) {
                int p = q[head++];
                int x = p / m, y = p % m;

                if (x > 0) {
                    int v = p - m;
                    char c = grid[x - 1][y];
                    if (c == '#') return dist + 1;
                    if (c != 'X') {
                        grid[x - 1][y] = 'X';
                        q.push_back(v);
                    }
                }

                if (x + 1 < n) {
                    int v = p + m;
                    char c = grid[x + 1][y];
                    if (c == '#') return dist + 1;
                    if (c != 'X') {
                        grid[x + 1][y] = 'X';
                        q.push_back(v);
                    }
                }

                if (y > 0) {
                    int v = p - 1;
                    char c = grid[x][y - 1];
                    if (c == '#') return dist + 1;
                    if (c != 'X') {
                        grid[x][y - 1] = 'X';
                        q.push_back(v);
                    }
                }

                if (y + 1 < m) {
                    int v = p + 1;
                    char c = grid[x][y + 1];
                    if (c == '#') return dist + 1;
                    if (c != 'X') {
                        grid[x][y + 1] = 'X';
                        q.push_back(v);
                    }
                }
            }

            ++dist;
        }

        return -1;
    }
};