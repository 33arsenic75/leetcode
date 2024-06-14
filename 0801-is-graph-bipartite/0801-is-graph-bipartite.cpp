class Solution {
public:
public:
    vector<vector<int>> graph;
    vector<int> v;

    bool isBipartite(vector<vector<int>>& graph) {
        this->graph = graph;
        int n = graph.size();
        v = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                v[i] = 0;
                bool f = colour(i);
                if (!f) return false;
            }
        }
        return true;
    }

    bool colour(int i) {
        for (int j : graph[i]) {
            if (v[j] == -1) {
                v[j] = 1 - v[i];
                bool res = colour(j);
                if (!res) return false;
            } else if (v[j] != 1 - v[i]) {
                return false;
            }
        }
        return true;
    }
};