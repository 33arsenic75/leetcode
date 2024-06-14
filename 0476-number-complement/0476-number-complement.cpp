class Solution {
public:
    int findComplement(int n) {
        if(n==0)return 1;
        else if(n==1)return 0;
        return 2*findComplement(n/2) + (1-n%2);
    }
};