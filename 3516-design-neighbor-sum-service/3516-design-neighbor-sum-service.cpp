class NeighborSum {
public:
    vector<vector<int>>a;
    int n;
    vector<int>adj,diag;
    bool inrange(int i,int j){
        return (i>=0) && (i<n) && (j>=0) && (j<n);
    }
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        a = grid;
        adj = vector<int>(n*n);
        diag = vector<int>(n*n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(inrange(i+1,j))adj[a[i][j]]+=a[i+1][j];
                if(inrange(i-1,j))adj[a[i][j]]+=a[i-1][j];
                if(inrange(i,j+1))adj[a[i][j]]+=a[i][j+1];
                if(inrange(i,j-1))adj[a[i][j]]+=a[i][j-1];
                if(inrange(i+1,j+1))diag[a[i][j]] += a[i+1][j+1];
                if(inrange(i+1,j-1))diag[a[i][j]] += a[i+1][j-1];
                if(inrange(i-1,j+1))diag[a[i][j]] += a[i-1][j+1];
                if(inrange(i-1,j-1))diag[a[i][j]] += a[i-1][j-1];

            }
        }
    }
    
    int adjacentSum(int value) {
        return adj[value];
    }
    
    int diagonalSum(int value) {
        return diag[value];
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */