class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};
    vector<vector<int>>grd;
    vector<vector<bool>>vis;
    bool inrange(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int n,m;
    int bfs(int i,int j){
        vis[i][j]=true;
        int sum=1;
        for(int k=0;k<4;k++){
            int xx=i+dx[k],yy=j+dy[k];
            if(inrange(xx,yy)){
                if(!vis[xx][yy] && grd[xx][yy]==1){
                    sum+=bfs(xx,yy);
                }
            }
        }
        cout<<i<<' '<<j<<' '<<sum<<'\n';
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        grd=grid;
        cout<<n<<' '<<m;
        cout<<'\n';
        vis=vector<vector<bool>>(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grd[i][j]==1 && !vis[i][j])ans=max(ans,bfs(i,j));
            }
        }
        return ans;
    }
};