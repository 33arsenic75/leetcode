class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>a(26,0),b(26,0);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            a[s[i]-'a']=i;
            b[t[i]-'a']=i;
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++)ans+=abs(a[i]-b[i]);
        return ans;
    }
};