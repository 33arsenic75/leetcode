class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            int c1 = str1[i]-'a';
            int c2 = str2[j]-'a';
            int gap1 = ((c1+1)%26-c2)%26;
            int gap2 = (c1-c2)%26;
            if(gap1==0 || gap2==0){
                j++;
            }
            i++;
        }
        return j==m;
    }
};