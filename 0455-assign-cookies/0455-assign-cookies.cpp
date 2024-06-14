class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size(),m=s.size();
        int i=0,j=0;
        int ans=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                ans++;
                j++;i++;
            }
            else j++;
        }
        return ans;
    }
};