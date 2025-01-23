class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int communicableServersCount = 0;
        vector<int> rowCounts(size(grid[0]), 0),
            lastServerInCol(size(grid), -1);
        for (int row = 0; row < size(grid); ++row) {
            int serverCountInRow = 0;
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col]) {
                    serverCountInRow++;
                    rowCounts[col]++;
                    lastServerInCol[row] = col;
                }
            if (serverCountInRow != 1)
                communicableServersCount += serverCountInRow,
                    lastServerInCol[row] = -1;
        }
        for (int row = 0; row < size(grid); ++row)
            communicableServersCount += lastServerInCol[row] != -1 &&
                                        rowCounts[lastServerInCol[row]] > 1;

        return communicableServersCount;
    }
};