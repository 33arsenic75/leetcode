class Solution {
public:
    // BFS to find shortest path from (x,y) to (tx,ty)
    int bfs_call(int x,int y,int tx,int ty,vector<vector<int>>& forest) {
        if(x==tx&&y==ty) return 0; // already there

        int n=forest.size();
        int m=forest[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{x,y}});
        visited[x][y]=1;

        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};

        while(!q.empty()) {
            auto [steps,coord]=q.front();
            q.pop();
            int cx=coord.first;
            int cy=coord.second;

            for(int k=0;k<4;k++) {
                int nx=cx+dx[k];
                int ny=cy+dy[k];

                if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]&&forest[nx][ny]!=0) {
                    if(nx==tx&&ny==ty) return steps+1;
                    visited[nx][ny]=1;
                    q.push({steps+1,{nx,ny}});
                }
            }
        }
        return -1; // unreachable
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();

        // Collect all trees (height>1)
        vector<pair<int,pair<int,int>>> trees;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(forest[i][j]>1) {
                    trees.push_back({forest[i][j],{i,j}});
                }
            }
        }

        // Sort trees by height
        sort(trees.begin(),trees.end());

        int total_steps=0;
        int x=0,y=0; // starting point

        for(auto& t:trees) {
            int tx=t.second.first;
            int ty=t.second.second;

            int dist=bfs_call(x,y,tx,ty,forest);
            if(dist==-1) return -1;

            total_steps+=dist;
            x=tx;
            y=ty; // move to new position
        }

        return total_steps;
    }
};