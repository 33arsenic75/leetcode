class Solution {
private:
    int findParent(vector<int>& parent, int cellIndex) {
        if (parent[cellIndex] == cellIndex) {
            return cellIndex;
        }
        return parent[cellIndex] = findParent(parent, parent[cellIndex]);
    }
    void unionComponents(vector<int>& parent, vector<int>& componentSize,
                         vector<int>& totalFish, int cellIndex1,
                         int cellIndex2) {
        int root1 = findParent(parent, cellIndex1);
        int root2 = findParent(parent, cellIndex2);

        if (root1 != root2) {
            if (componentSize[root1] < componentSize[root2]) {
                swap(root1, root2);
            }
            parent[root2] = root1;
            componentSize[root1] += componentSize[root2];
            totalFish[root1] += totalFish[root2];
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rowCount = grid.size(), columnCount = grid[0].size();
        int totalCells = rowCount * columnCount;
        vector<int> parent(totalCells);
        vector<int> componentSize(totalCells, 1);
        vector<int> totalFish(totalCells);
        iota(parent.begin(), parent.end(), 0);
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                int cellIndex = row * columnCount + column;
                totalFish[cellIndex] = grid[row][column];
            }
        }
        vector<int> deltaRow{0, 0, 1, -1}, deltaColumn{1, -1, 0, 0};
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (grid[row][column] > 0) {
                    int cellIndex = row * columnCount + column;
                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = row + deltaRow[direction];
                        int neighborColumn = column + deltaColumn[direction];
                        if (neighborRow >= 0 && neighborRow < rowCount &&
                            neighborColumn >= 0 &&
                            neighborColumn < columnCount &&
                            grid[neighborRow][neighborColumn] > 0) {
                            int neighborIndex =
                                neighborRow * columnCount + neighborColumn;
                            unionComponents(parent, componentSize, totalFish,
                                            cellIndex, neighborIndex);
                        }
                    }
                }
            }
        }
        int maxFish = 0;
        for (int cellIndex = 0; cellIndex < totalCells; cellIndex++) {
            if (findParent(parent, cellIndex) ==
                cellIndex) {
                maxFish = max(maxFish, totalFish[cellIndex]);
            }
        }
        return maxFish;
    }
};