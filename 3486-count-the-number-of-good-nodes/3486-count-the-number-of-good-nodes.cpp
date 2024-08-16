using ll = long long;
class Solution {
public:

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = 0;
        for(vector<int>e:edges){
            n = max(n,1+max(e[0],e[1]));
        }
        vector<vector<ll>>adj(n);
        for(vector<int>e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>sz(n,1);
        vector<vector<ll>>child(n);
        function<void(ll,ll)>dfs = [&](ll at,ll p){
            for(ll to:adj[at]){
                if(to==p)continue;
                child[at].push_back(to);
                dfs(to,at);
                sz[at]+=sz[to];
            }
        };
        dfs(0,-1);
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++){
            if(child[i].size()==0){
                ans++;
            }
            else{
                ll szz = sz[child[i][0]];
                bool possible = true;
                for(ll to:child[i]){
                    if(sz[to]!=szz){
                        possible = false;
                        break;
                    }
                }
                ans += possible;
            }
        }
        return ans;
    }
};