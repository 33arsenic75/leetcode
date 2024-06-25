class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prm(n,true);
        long long cnt = 0;
        for(long long i = 2; i < n ; i++){
            if(prm[i]){
                cnt++;
                for(long long j = i*i ; j < n ; j+=i)prm[j]=false;
            }
        }
        return cnt;
    }
};