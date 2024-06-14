class Solution {
public:
    int tribonacci(int n) {
        vector<int>a(max(n+1,3),0);
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(int i = 3 ; i <= n ; i++){
            a[i] = a[i-1] + a[i-2] + a[i-3];
        }
        return a[n];
    }
};