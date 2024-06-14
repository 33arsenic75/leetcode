class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int common = 0;
        while(left!=right){
            left>>=1;
            right>>=1;
            common++;
        }
        return left<<common;
    }
};