class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int i = 0; int n = s.size();
        while(i<n && s[i]==' ')i++;
        int ans = 0;
        while(i<n && s[i]!=' '){
            i++;
            ans++;
        }
        return ans;
    }
};