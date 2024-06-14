class Solution {
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int i,int j){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<int>rItr={-1,0,1,0};
        vector<int>cItr={0,1,0,-1};
        q.push({i,j});
        while(!q.empty()){
            int ii=q.front().first;
            int jj=q.front().second;
            q.pop();
            for(int dir=0;dir<4;dir++){
                int nr=ii+rItr[dir];
                int nc=jj+cItr[dir];
                if(nr>=0 && nr<n  &&  nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};