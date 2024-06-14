class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};


    void bfs(queue<vector<int>> q, vector<vector<int>> &arr){
        int n = arr.size();
        int m = arr[0].size();
        
        while(q.size()!=0){
            vector<int> a = q.front();
            q.pop();
            int r = a[0];
            int c = a[1];
            for(int k=0; k<4; k++){
                int nr = r+dir[k][0];
                int nc = c+dir[k][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]==-1){
                    arr[nr][nc] = arr[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        queue<vector<int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==0){
                    q.push({i,j});
                }else{
                    arr[i][j] = -1;
                }
            }
        }

        bfs(q,arr);
        return arr;
    }
};