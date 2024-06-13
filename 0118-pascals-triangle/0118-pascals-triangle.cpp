class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>temp(numRows);
        temp[0] = {1};
        for(int i = 1 ; i < numRows; i ++){
            temp[i] = vector<int>(i+1,1);
            for(int j = 1 ; j < i ; j++){
                temp[i][j] = temp[i-1][j-1] + temp[i-1][j];
            }
        }
        return temp;
    }
};