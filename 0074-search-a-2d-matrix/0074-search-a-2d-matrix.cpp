class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = row*col - 1, mid = -1, value;
        while (left <= right) {
            mid = left + (right-left)/2;
            value = matrix[mid/col][mid%col];
            cout << "Value: " << value << endl;
            if (value == target) {
                return true;
            } else if (target < value) {
                right = mid-1;
            } else { // target > value
                left = mid + 1;
            }
        }
        return false;
    }
};