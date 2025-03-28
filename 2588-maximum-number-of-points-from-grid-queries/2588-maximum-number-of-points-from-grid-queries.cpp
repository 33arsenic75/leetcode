class Solution {
public:
    vector<vector<int>> a;
    int n, m;
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        a = grid;
        n = grid.size(), m = grid[0].size();
        int k = queries.size();
        vector<int> ans(k, 0);

        vector<pair<int, int>> indexed_queries;
        for (int i = 0; i < k; i++) {
            indexed_queries.push_back({queries[i], i});
        }
        
        sort(indexed_queries.begin(), indexed_queries.end());  // Sort queries in increasing order
        map<int, int> cache; // Caching results for already computed queries

        queue<pair<int, int>> q;
        queue<pair<int, int>> qnext;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({0, 0});
        int score = 0;  // Count of traversed cells
        
        for (int qIdx = 0; qIdx < k; qIdx++) {
            int num = indexed_queries[qIdx].first;
            int originalIdx = indexed_queries[qIdx].second;
            
            // If the result for `num` is already computed, use cache
            if (cache.find(num) != cache.end()) {
                ans[originalIdx] = cache[num];
                continue;
            }

            // Process BFS for new `num`
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                
                if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) continue;
                
                if (a[i][j] < num) {
                    vis[i][j] = true;
                    score++;
                    
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i - 1, j});
                    q.push({i, j - 1});
                } else {
                    qnext.push({i, j});
                }
            }

            // Store the computed score in cache and result
            ans[originalIdx] = score;
            cache[num] = score;
            swap(q, qnext);
        }
        
        return ans;
    }
};
