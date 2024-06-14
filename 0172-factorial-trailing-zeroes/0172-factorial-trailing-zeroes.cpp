class Solution {
public:
    int trailingZeroes(int n) {
        int temp = n;
        int five = 0;
        while(temp>0){
            five += temp/5;
            temp/=5;
        }
        return five;
    }
};