class Solution {
public:
    const int INF = INT_MAX;

    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n == 0)return;
        int m = rooms[0].size();

        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0)
                    q.push({i, j});
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                if(rooms[ni][nj] != INF)
                    continue;

                rooms[ni][nj] = rooms[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
};