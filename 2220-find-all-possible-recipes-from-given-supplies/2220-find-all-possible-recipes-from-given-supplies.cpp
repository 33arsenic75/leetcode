class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // sort(supplies.begin(),supplied.end());
        map<string,int>mp;
        map<int,string>rmp;
        int start = 0;
        for(string&s : recipes){
            if(mp[s]==0){
                mp[s] = start;
                rmp[start] = s;
                start++;
            }
        }
        for(vector<string>&v:ingredients){ 
            for(string&s : v){
                if(mp[s]==0){
                    mp[s] = start;
                    rmp[start] = s;
                    start++;
                }
            }
        }
        for(string&s : supplies){
            if(mp[s]==0){
                mp[s] = start;
                rmp[start] = s;
                start++;
            }
        }
        int mx = start;
        int n = recipes.size();
        vector<vector<int>>adj(mx);
        vector<int>indeg(mx,0);
        vector<int>maxdeg(mx,0);
        for(int i = 0 ; i < n ; i++){
            int idx = mp[recipes[i]];
            for(string&s : ingredients[i]){
                // adj[idx].push_back(mp[s]);
                adj[mp[s]].push_back(idx);
            }
            maxdeg[idx] = ingredients[i].size();
        }
        queue<int>q;
        vector<bool>vis(mx,false);
        for(string&s: supplies){
            q.push(mp[s]);
            indeg[mp[s]] = maxdeg[mp[s]];
        }
        while(!q.empty()){
            int at = q.front();
            q.pop();
            if(vis[at])continue;
            vis[at]=true;
            for(int to: adj [at]){
                indeg[to] ++;
                if(indeg[to] >= maxdeg[to])q.push(to);
            }
        }
        vector<string>ans;
        // for(int i = 0 ; i < mx ; i++){
        //     if(vis[i])cout<<rmp[i]<<" "<<i<<"\n";
        // }
        for(string&s : recipes){
            if(vis[mp[s]])ans.push_back(s);
        }
        return ans;
    }
};