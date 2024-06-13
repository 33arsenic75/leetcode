class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pre(n,0),suf(n,0);
        pre[0]=height[0];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],height[i]);
        suf[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)suf[i]=max(suf[i+1],height[i]);
        int ans=0;
        for(int i=0;i<n;i++)ans+=min(pre[i],suf[i])-height[i];
        return ans;
    }
};