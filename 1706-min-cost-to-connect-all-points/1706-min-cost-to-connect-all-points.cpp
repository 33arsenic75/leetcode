class Solution {
public:

    class UF {
    public:
    int *id, cnt, *sz;
    // Create an empty union find data structure with N isolated sets.
    UF(int N) {
        cnt = N; id = new int[N]; sz = new int[N];
        for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
    ~UF() { delete[] id; delete[] sz; }
    // Return the id of component corresponding to object p.
    int find(int p) {
        int root = p;
        while (root != id[root])    root = id[root];
        while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
        return root;
    }
    // Replace sets containing x and y with their union.
    void merge(int x, int y) {
        int i = find(x); int j = find(y); if (i == j) return;
        // make smaller root point to larger one
        if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
        else { id[j] = i, sz[i] += sz[j]; }
        cnt--;
    }
    // Are objects x and y in the same set?
    bool connected(int x, int y) { return find(x) == find(y); }
    // Return the number of disjoint sets.
        int count() { return cnt; }
    };
    struct  Edge{
        int from; int to;
        int weight;
        Edge(int from, int to, int weight):from(from), to(to), weight(weight){
        }
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
        bool operator>(const Edge& other) const {
            return weight > other.weight;
        }
    };
    struct Graph{
        int n;
        vector<vector<Edge>> adj;
        vector<Edge> edges;
        bool directed;
        Graph(int n, bool directed):n(n),directed(directed){
            adj.resize(n+1);
        }
        void addEdge(int from, int to, int weight){
            Edge e1(from, to, weight);
            adj[from].push_back(e1);
            edges.push_back(e1);
            if(!directed){
                Edge e2(to, from, weight);
                adj[to].push_back(e2);
                edges.push_back(e2);
            }
        }
    };
    int mst(Graph G){
        int n = G.n;
        vector<Edge>edges = G.edges;
        vector<bool>vis(n+1,false);
        vector<Edge>ans;
        priority_queue<Edge,vector<Edge>,greater<Edge>>pq(edges.begin(),edges.end());
        UF uf(n+1);
        int mincost = 0;
        while(!pq.empty()){
            Edge e = pq.top();
            pq.pop();
            if(!uf.connected(e.from,e.to)){
                uf.merge(e.from,e.to);
                ans.push_back(e);
                mincost+=e.weight;
            }
        }
        bool mstexist = (ans.size()==n-1);
        return mincost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        Graph G(n,false);
        int dis = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1; j < n ; j++){
                dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                G.addEdge(i,j,dis);
            }
        }
        return mst(G);
    }
};