class Solution {
public:
    int f(int n){
        if(n==0)return 0;
        else if(n&1)return 1;
        return 2;
    }
    int minimumLength(string s) {
        int sz = 0;
        for(int i = 0 ; i < 26 ; i++){
            char c = i + 'a';
            int cnt = count(s.begin(),s.end(),c);
            sz += min(2,f(cnt));
        }
        return sz;
    }
};