class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4==0)n/=4;
            else break;
        }
        return (n==1);        
    }
};