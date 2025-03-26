class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> numsArray;
        int result = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) { 
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        int prefixIndex = 0;
        int suffixIndex = length - 1;
        while (prefixIndex < suffixIndex) {
            if (prefixIndex < length - suffixIndex - 1) {
                int prefixOperations =
                    (prefixIndex + 1) *
                    (numsArray[prefixIndex + 1] - numsArray[prefixIndex]) / x;
                result += prefixOperations;
                prefixIndex++;
            } else {
                int suffixOperations =
                    (length - suffixIndex) *
                    (numsArray[suffixIndex] - numsArray[suffixIndex - 1]) / x;
                result += suffixOperations;
                suffixIndex--;
            }
        }

        return result;
    }
};