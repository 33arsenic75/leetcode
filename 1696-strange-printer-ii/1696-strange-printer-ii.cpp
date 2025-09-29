class Solution {
public:
    bool isPrintable(vector<vector<int>>& tg) {
        vector<vector<bool>>adj(61,vector<bool>(61,false));
        vector<int>indeg(61, 0);
        vector<bool>vis(61, false);
        int n = tg.size();
        int m = tg[0].size();

        for(int c = 1 ; c <= 60; c++){
            int minx = n+1, miny = m+1, maxx = -1, maxy = -1;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(tg[i][j]==c){
                        minx = min(minx, i);
                        miny = min(miny, j);
                        maxx = max(maxx, i);
                        maxy = max(maxy, j);
                    }
                }
            }
            for(int i = minx ; i <= maxx ; i++){
                for(int j = miny ; j <= maxy ; j++){
                    if(tg[i][j]!=c)adj[c][tg[i][j]]=true;
                }
            }
        }
        queue<int>q;
        for(int c = 1 ; c <= 60 ; c++){
            for(int c2 = 1 ; c2 <= 60 ; c2++){
                if(adj[c][c2])indeg[c2]++;
            }
        }
        for(int c = 1 ; c <= 60 ; c++){
            if(indeg[c]==0)q.push(c);
            // cout<<c<<" "<<indeg[c]<<"\n";
        } 

        while(!q.empty()){
            int at = q.front();
            q.pop();
            vis[at] = true;
            for(int c = 1 ; c <= 60 ; c++){
                if(adj[at][c]){
                    indeg[c]--;
                    if(indeg[c]==0)q.push(c);
                }
            }
        }
        return (accumulate(indeg.begin(), indeg.end(), 0ll)==0ll);
    }
};