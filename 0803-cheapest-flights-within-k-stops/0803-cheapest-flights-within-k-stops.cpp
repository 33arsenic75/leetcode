class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        for(int i=0; i<flight.size();i++){
            n = max(n,max(flight[i][0],flight[i][1]));
        }
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0; i<flight.size(); i++){
            graph[flight[i][0]].push_back({flight[i][1],flight[i][2]});
        }
        queue<pair<pair<int,int>,int>> q;
        q.push({{src,0},0});
        vector<int> node(n+1,INT_MAX);
        node[src] = 0;
        unordered_map<int,bool> vis;
        while(!q.empty()){
            int val = q.front().first.first;
            int price = q.front().first.second;
            int passes = q.front().second;
            q.pop();
            for(int i=0; i<graph[val].size(); i++){
                if(node[graph[val][i].first]>price+graph[val][i].second && k>=passes){
                    node[graph[val][i].first] = price+graph[val][i].second;
                    q.push({{graph[val][i].first,price+graph[val][i].second},passes+1});
                }
            }
            
        }
        return node[dst]!=INT_MAX?node[dst]:-1;
        
    }
};