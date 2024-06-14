class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& v) {
        vector<int>adj[n];
        vector<pair<int,int>>deg(n);///in,out
        for(int i=0;i<v.size();i++){
            adj[v[i][0]].push_back(v[i][1]);
            deg[v[i][0]].second++;
            deg[v[i][1]].first++;
        }
        vector<set<int>>ans(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            cout<<deg[i].first<<' '<<deg[i].second<<endl;
            if(deg[i].first==0)q.push(i);
        }
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(int j:adj[i]){
                deg[j].first--;
                if(deg[j].first==0)q.push(j);
                ans[j].insert(i);
                for(int k:ans[i]){
                    ans[j].insert(k);
                }
            }
        }
        vector<vector<int>>a(n);
        for(int i=0;i<n;i++){
            for(int j:ans[i]){
                a[i].push_back(j);
            }
        }
        return a;
    }
};