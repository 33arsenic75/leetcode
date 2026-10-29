class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string ans(n+m, ' ');
        int i = 0;
        int j = 0;
        int idx = 0;

        while( (i<n) && (j<m)){
            // compare remaining suffixes, not just current chars
            if(word1.compare(i, n-i, word2, j, m-j) > 0){
                ans[idx] = word1[i];
                i++;
            }
            else{
                ans[idx] = word2[j];
                j++;
            }
            idx++;
        }

        while(i<n){
            ans[idx] = word1[i];
            i++;
            idx++;
        }

        while(j<m){
            ans[idx] = word2[j];
            j++;
            idx++;
        }
        return ans;
    }
};
