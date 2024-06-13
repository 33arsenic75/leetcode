class Solution {
public:
    map<int,int>mp;
    void convolution(int n){
        mp[n]=0;
        for(int i = 0; i < n ; i++){
            mp[n]+=mp[i]*mp[n-1-i];
        }
    }
    int numTrees(int n) {
        mp[0]=1;
        for(int i = 1 ; i <= n ; i++)convolution(i);
        return mp[n];
    }
};
// 1 -> 0 * 2
// 2 -> 1 * 1
// 3 -> 2 * 0
// f(n) = summation 