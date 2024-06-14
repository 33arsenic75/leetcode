class Solution {
public:
    vector<long long>prm;
    void help(long long n){
        prm.push_back(2);
        vector<long long>a(n,true);
        for(long long i = 3 ;  i < n ; i+=2){
            if(!a[i])continue;
            prm.push_back(i);
            for(long long j = i*i ; j < n ; j+=i){
                a[j]=false;
            }
        }
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        help(n);
        return prm.size();
    }
};