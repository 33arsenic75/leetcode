class Solution {
public:
    int swaps(vector<int> a) {
        int n = a.size();
        vector<pair<int, int>> dup;
        for (int i = 0; i < n; i++) {
            dup.emplace_back(a[i], i);
        }
        sort(dup.begin(), dup.end());
        vector<bool> visited(n, false);
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || dup[i].second == i) continue;
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = dup[j].second;
                cycle_size++;
            }
            if (cycle_size > 1) {
                op += cycle_size - 1;
            }
        }
        return op;
    }

    int minimumOperations(TreeNode* root) {
        map<int, vector<int>> mp;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* r, int d) {
            if (!r) return;
            mp[d].push_back(r->val);
            dfs(r->left, d + 1);
            dfs(r->right, d + 1);
        };
        int ans = 0;
        dfs(root, 0);
        for (auto& [k, v] : mp) {
            // cout << "Level " << k << ": ";
            // for (int i : v) cout << i << " ";
            // cout << '\n';
            ans += swaps(v);
            // cout << "Operations after level " << k << ": " << ans << '\n';
        }

        return ans;
    }
};
