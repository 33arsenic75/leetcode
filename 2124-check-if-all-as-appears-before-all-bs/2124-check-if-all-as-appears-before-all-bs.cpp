class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int max_a = -1;
        int min_b = n;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a')max_a = i;
            if(s[n-1-i] == 'b')min_b = n-i-1;
        }
        return max_a < min_b;
    }
};