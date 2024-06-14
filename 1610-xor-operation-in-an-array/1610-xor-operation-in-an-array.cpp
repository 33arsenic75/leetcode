class Solution {
public:
    int xorOperation(int n, int start) {
        int flag = false;
        if ((start&1) && (n&1)) flag = true;
        int s = start >> 1;
        int e = (start + (n-1)*2) >> 1;
        if (s == 0) {
            int ans = findXor(e);
            ans <<= 1;
            return flag? ans | 1 : ans;
        }
        else{
            int ans = findXor(e) ^ findXor(s-1);
            ans <<= 1;
            return flag? ans | 1 : ans;
        }
    }
private:
    int findXor(int n){
        int y = n%4;
        switch(y) {
            case  0:
                return n;
            case  1:
                return 1;
            case  2:
                return n+1;
            case  3:
                return 0;
            default :
                return -1;
        }
    }
};