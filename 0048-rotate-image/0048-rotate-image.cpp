class Solution {
public:
    void rotate(int& a, int& b, int& c, int& d){
        int temp = d;
        d = c;
        c = b;
        b = a;
        a = temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < (n + 1) / 2; j++) {
                rotate(matrix[i][j], matrix[j][n - 1 - i], matrix[n - 1 - i][n - 1 - j], matrix[n - 1 - j][i]);
            }
        }
    }
};
