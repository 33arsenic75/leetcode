class Solution {
public:
    vector<vector<char>>b;
    int n,m;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<vector<bool>>v;
    bool inrange(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void bfs(int i, int j) {
        cout << i << ' ' << j << '\n';
        v[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int xx = i + dx[k], yy = j + dy[k];
            if (inrange(xx, yy) && b[xx][yy] == 'O' && !v[xx][yy]) {
                bfs(xx, yy);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        b=board;
        v=vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(b[0][i]=='O' && !v[0][i])bfs(0,i);
            if(b[n-1][i]=='O' && !v[n-1][i])bfs(n-1,i);
        }
        for(int i=0;i<n;i++){
            if(b[i][0]=='O' && !v[i][0])bfs(i,0);
            if(b[i][m-1]=='O' && !v[i][m-1])bfs(i,m-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j])board[i][j]='X';
            }
        }
    }
};