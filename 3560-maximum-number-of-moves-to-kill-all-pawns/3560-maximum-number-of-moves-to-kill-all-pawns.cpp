class Solution {
public:
    vector<vector<int>> dirns={
        {2,1},
        {2,-1},
        {-2,1},
        {-2,-1},
        {1,2},
        {1,-2},
        {-1,2},
        {-1,-2}
    };
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }      
    void bfs(int x,int y,int idx,vector<vector<int>>&mindist,vector<vector<int>>&pos){
        vector<vector<int>> t(50,vector<int>(50,-1));
        queue<pair<int,int>> q;
        q.push({x,y});
        t[x][y]=0;
        while(!q.empty()){
            auto [i,j]=q.front(); q.pop();
            for(auto&d:dirns){
                int nx=i+d[0];
                int ny=j+d[1];
                if(isValid(nx,ny,50,50) && t[nx][ny]==-1){
                    t[nx][ny]=1+t[i][j];
                    q.push({nx,ny});
                }
            } 
        }
        for(int i=0;i<pos.size();i++){
            int row=pos[i][0];
            int col=pos[i][1];
            mindist[idx][i]=t[row][col];
        }
    }
    int solve(vector<vector<int>>&mindist,int idx,int mask,int n,bool alice,int dp[51][1<<15]){

        if(mask==0){
            return 0;//no more steps/moves req;
        }
        //alr computed
        if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        int res;
        if(alice==true){//alice's move
            res=-1;//maximize
        }else{//bob's move
            res=1e9;//minimize
        }
        //try all rem pawns
        for(int i=1;i<n;i++){
            if(mask & (1<<(i-1))){
                int moves=mindist[idx][i];
                if(alice==true){//alice for max
                    res=max(res,moves+solve(mindist,i,mask^(1<<(i-1)),n,!alice,dp));
                }else{//bob want to minimize
                    res=min(res,moves+solve(mindist,i,mask^(1<<(i-1)),n,!alice,dp));
                }
            }
        }
        return dp[idx][mask]=res;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n=positions.size();
        // Position vector: knight + all pawns
        vector<vector<int>> pos;//store all posn of pawns as well as knight's start coords
        pos.push_back({kx,ky});//knight's start
        for(auto&vec:positions){
            pos.push_back({vec[0],vec[1]});
        }
        //mindist[i][j]= min knight moves from pos[i] to pos[j]
        vector<vector<int>> mindist(n+1,vector<int>(n+1,0));
        for(int i=0;i<pos.size();i++){
            int x=pos[i][0];
            int y=pos[i][1];
            bfs(x,y,i,mindist,pos);
        }
        //call solve
        //knight at 0th idx in pos arr
        // All pawns present: bitmask with all n bits set
        int allNbitsSet_to_1=(1<<n)-1;
        bool alice=true;//start rec simulation with Alice's turn
        int dp[51][1<<15];
        memset(dp,-1,sizeof(dp));
        return solve(mindist,0,allNbitsSet_to_1,pos.size(),alice,dp);
    }
};