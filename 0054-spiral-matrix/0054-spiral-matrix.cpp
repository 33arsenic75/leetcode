class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lowR=0, lowC=0;
        int highR = matrix.size()-1;
        int highC = matrix[0].size()-1;
        vector<int> result;

        while (lowR<=highR || lowC<=highC) {
            if (lowR <= highR) {
                for (int c = lowC; c <= highC; c++) {
                    result.push_back(matrix[lowR][c]);
                }
                lowR++;
            }
            if (lowC <= highC) {
                for (int r = lowR; r <= highR; r++) {
                    result.push_back(matrix[r][highC]);
                }
            }
            highC--;
            if (lowR <= highR) {
                for (int c = highC; c >= lowC; c--) {
                    result.push_back(matrix[highR][c]);
                }
                highR--;    
            }
            if (lowC <= highC) {
                for (int r = highR; r >= lowR; r--) {
                    result.push_back(matrix[r][lowC]);
                }
                lowC++;
            }
        }
        return result;
    }
};