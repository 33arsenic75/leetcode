class Solution {
public:
    int dp[1001][1001];
    int nerd(int index,int used,int total,int len,vector<int>&v){
        if(index>=v.size() or used==total) return 0;
        if(dp[index][used]!=-1) return dp[index][used];
        int notusing=nerd(index+1,used,total,len,v);
        int usingt=nerd(index+len,used+1,total,len,v);
        int wscovered;
        if(index>0) wscovered=v[index-1];
        else wscovered=0;
        if(index+len>=v.size()) wscovered=v[v.size()-1]-wscovered;
        else wscovered=v[index+len-1]-wscovered;
        return dp[index][used]=max(wscovered+usingt,notusing);
    }
    int minimumWhiteTiles(string s, int n, int l) {
        if(s.size()<=n*l) return 0;
        memset(dp,-1,sizeof(dp));
        vector<int>v(s.size());
        for(int i=0;i<s.size();i++) v[i]=s[i]-'0';
        for(int i=1;i<s.size();i++) v[i]+=v[i-1];
        return v[v.size()-1]-nerd(0,0,n,l,v);
    }
};