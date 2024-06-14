class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int ans = 0;
        int i = 0;
        while(n){
            if(!(n&1))ans+=(1<<i);
            n/=2;
            i++;
        }
        return ans;
    }
};