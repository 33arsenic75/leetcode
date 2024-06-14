class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int,int>>v[n];///dist,id
        vector<int>dist(n,INT_MAX);
        vector<bool>vis(n,false);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;///dist,id
        pq.push({0,0});
        for(vector<int>w:edges){
            v[w[0]].push_back({w[2]+1,w[1]});
            v[w[1]].push_back({w[2]+1,w[0]});
        }
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            if(vis[p.second])continue;
            vis[p.second]=true;
            for(pair<int,int>q:v[p.second]){
                int alt=q.first+p.first;
                if(alt<dist[q.second]){
                    dist[q.second]=alt;
                    pq.push({alt,q.second});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<i<<' '<<dist[i]<<endl;
        }
        for(vector<int>e:edges){
            if(!vis[e[0]])continue;
            else if(dist[e[0]]<=maxMoves && dist[e[1]]<=maxMoves){
                ans+=min(e[2],2*maxMoves-dist[e[0]]-dist[e[1]]);
            }
            else if(dist[e[0]]>maxMoves && dist[e[1]]>maxMoves)continue;
            else if(dist[e[0]]<=maxMoves){
                ans+=maxMoves-dist[e[0]];
            }
            else if(dist[e[1]]<=maxMoves){
                ans+=maxMoves-dist[e[1]];
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]&& dist[i]<=maxMoves)ans++;
        }
        return ans;
    }
};