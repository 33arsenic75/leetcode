class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string ans(n+m,' ');
        int i = 0, j = 0,k = 0;
        while(k<n+m){
            if(j<m && i==spaces[j]){
                ans[k]=' ';
                ans[k+1]=s[i];
                k+=2;
                i++;
                j++;
            }
            else{
                ans[k]=s[i];
                k++;
                i++;
            }
        }
        return ans;

    }
};