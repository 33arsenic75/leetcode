class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int columns = isWater[0].size();
        const int INF = rows * columns;
        vector<vector<int>> cellHeights(rows, vector<int>(columns, INF));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (isWater[row][col]) {
                    cellHeights[row][col] = 0;
                }
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                int minNeighborDistance = INF;
                int neighborRow = row - 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                neighborRow = row;
                neighborCol = col - 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = columns - 1; col >= 0; col--) {
                int minNeighborDistance = INF;
                int neighborRow = row + 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                neighborRow = row;
                neighborCol = col + 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }
        return cellHeights;
    }

private:
    bool isValidCell(int row, int col, int rows, int columns) {
        return row >= 0 && col >= 0 && row < rows && col < columns;
    }
};