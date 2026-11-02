class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>reach(n, vector<int>(m, 0));
        vector<vector<int>>dist(n, vector<int>(m, 0));

        int total = 0;
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 1) continue;
                total++;

                queue<pair<int,int>>q;
                vector<vector<bool>>vis(n, vector<bool>(m, false));

                q.push({i,j});
                vis[i][j] = true;

                int d = 0;

                while(!q.empty()){
                    int sz = q.size();

                    while(sz--){
                        auto [x,y] = q.front();
                        q.pop();

                        if(grid[x][y] == 0){
                            reach[x][y]++;
                            dist[x][y] += d;
                        }

                        for(int k = 0 ; k < 4 ; k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                                continue;

                            if(vis[nx][ny] || grid[nx][ny] != 0)
                                continue;

                            vis[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }

                    d++;
                }
            }
        }

        int ans = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0 && reach[i][j] == total){
                    ans = min(ans, dist[i][j]);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};