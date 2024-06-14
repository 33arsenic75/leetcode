class Solution {
public:
    
    double memo[26][26][101];
    int dxy[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    
    double prob(int n, int k, int r, int c){
        if(memo[r][c][k]!=0) return memo[r][c][k];
        
        if(k==0) return 1; // probability of staying inside chess board after k moves
        
        double ans=0;
        for(int d=0;d<8;d++){
            int x=r+dxy[d][0], y=c+dxy[d][1];
            
            if(x>=0 && y>=0 && x<n && y<n) ans+=0.125*prob(n,k-1,x,y);
        }
        return memo[r][c][k]=ans;
    }
    
    double knightProbability(int n, int k, int r, int c) {
       return prob(n,k,r,c);
    }
};