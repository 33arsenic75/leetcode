class Solution {
public:
   int findpar(int node,vector<int> &par){
        if(par[node]==node) return node;

        return par[node]=findpar(par[node],par);
    }
    
    void unionbyrank(int x,int y,vector<int> &par,vector<int> &rank){
        
        int u=findpar(x,par);
        int v=findpar(y,par);
        
        if(rank[u]>rank[v]){
        par[v]=u;
        rank[u]+=rank[v];
     
    }
    else if(rank[v]>rank[u]){
         par[u]=v;
         rank[v]+=rank[u];
      
    }
    else{
        par[v]=u;
        rank[u]+=rank[v];
       
    }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        
        vector<int> par(n+1);
        vector<int> rank(n+1);
        
        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=1;
        }
        
        for(int i=threshold+1;i<=n;i++){
            
            for(int j=2;j*i<=n;j++){
                
                if(findpar(i,par)!=findpar(j*i,par)){
                    unionbyrank(i,i*j,par,rank);
                }
            }
        }
        
        int q=queries.size();
        vector<bool> ans(q,false);
        
        for(int i=0;i<q;i++){
            
            if(findpar(queries[i][0],par)==findpar(queries[i][1],par)){
                ans[i]=true;
            }
        }
        
        
        return ans;
    }
};