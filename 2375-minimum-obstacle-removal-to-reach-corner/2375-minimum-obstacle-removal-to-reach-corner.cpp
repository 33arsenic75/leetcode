class Solution {
public:
    bool inrange(int x,int y,int n, int m){
        return x>=0 && x<n && y>=0&& y<m;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        vector<vector<int>>dis(n,vector<int>(m,n+m+1));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dis[0][0]=grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({dis[0][0],{0,0}});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.first;
            int x = top.second.first, y = top.second.second;
            if(vis[x][y])continue;
            vis[x][y]=true;
            for(int i = 0 ; i < 4 ; i++){
                if(inrange(x+dx[i],y+dy[i],n,m)){
                    dis[x+dx[i]][y+dy[i]]=min(dis[x+dx[i]][y+dy[i]],grid[x+dx[i]][y+dy[i]]+d);
                    pq.push({dis[x+dx[i]][y+dy[i]],{x+dx[i],y+dy[i]}});
                }
            }
        }
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < m ; j++)cout<<dis[i][j]<<" ";
        //     cout<<'\n';
        // }
        return dis[n-1][m-1];
    }
};