#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class DSU {
public:
    vector<int> rank, parent;

    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void UnionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        inc();

        int n = *max_element(nums.begin(), nums.end()) + 1;
        DSU dsu(n);

        for (int& val : nums) {
            for (int i = 2; i * i <= val; i++) {

                if (val % i == 0) {
                    dsu.UnionByRank(i, val);
                    dsu.UnionByRank(val, val / i);
                }
                
            }
        }

        int result = 0;
        unordered_map<int, int> mp;

        for (int& val : nums) {
            int parent = dsu.find(val);
            mp[parent]++;
            result = max(result, mp[parent]);
        }

        return result;
    }
};