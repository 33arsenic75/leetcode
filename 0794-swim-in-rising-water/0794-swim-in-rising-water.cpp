class Solution {
public:
    using int2=array<int, 2>;
    int n;
    int to1D(int i, int j){
        return i*n+j;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==1) return 0;// edge case
        vector<int> dist(n*n, INT_MAX);
        dist[0]=0;
        vector<bool> visited(n*n, 0);
        int dir[][2]={{-1, 0},{1, 0},{0, -1},{0, 1}};
        priority_queue<int2, vector<int2>, greater<int2>> pq;
        pq.push({0, 0});// (dist, to1D(i, j))

        while (!pq.empty()) {
            auto [d, idx] = pq.top();
            auto [i, j]=div(idx, n);
            pq.pop();
            if (d>dist[idx]) continue;
            if (idx==n*n-1) return d;
            visited[idx]=1;
            int d2;
            for (auto& dd: dir){
                int r=i+dd[0], s=j+dd[1];
                int&& idx2=to1D(r, s);
                if(r<0||r>=n||s<0||s>=n||visited[idx2]) continue;
                int w=max(grid[i][j], grid[r][s]);
                d2=max(d, w);
                if (d2 < dist[idx2]) {
                    dist[idx2] = d2;
                    pq.push({d2, idx2});
                }
            }
        }
        return 0;
    }
};