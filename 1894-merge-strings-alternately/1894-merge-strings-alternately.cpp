class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string ans(n+m,' ');
        int i = 0, j = 0;int targ = 0;
        while(i<n && j<m){
            ans[targ] = word1[i];
            ans[targ+1] = word2[j];
            i++;
            j++;
            targ+=2;
        }
        while(i<n){
            ans[targ]=word1[i];
            i++;
            targ++;
        }
        while(j<m){
            ans[targ]=word2[j];
            j++;
            targ++;
        }
        return ans;
    }
};