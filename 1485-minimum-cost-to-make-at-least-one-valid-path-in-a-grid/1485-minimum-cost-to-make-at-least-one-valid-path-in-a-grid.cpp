class Solution {
private:
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), cost = 0;
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        queue<pair<int, int>> queue;
        dfs(grid, 0, 0, minCost, cost, queue);
        while (!queue.empty()) {
            cost++;
            int levelSize = queue.size();
            while (levelSize-- > 0) {
                auto [row, col] = queue.front();
                queue.pop();
                for (int dir = 0; dir < 4; dir++) {
                    dfs(grid, row + dirs[dir][0], col + dirs[dir][1], minCost,
                        cost, queue);
                }
            }
        }
        return minCost[numRows - 1][numCols - 1];
    }

private:
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<int>>& minCost, int cost,
             queue<pair<int, int>>& queue) {
        if (!isUnvisited(minCost, row, col)) return;
        minCost[row][col] = cost;
        queue.push({row, col});
        int nextDir = grid[row][col] - 1;
        dfs(grid, row + dirs[nextDir][0], col + dirs[nextDir][1], minCost, cost,
            queue);
    }
    bool isUnvisited(vector<vector<int>>& minCost, int row, int col) {
        return row >= 0 && col >= 0 && row < minCost.size() &&
               col < minCost[0].size() && minCost[row][col] == INT_MAX;
    }
};