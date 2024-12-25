#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
            if (!node) return;
            if (depth == ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[depth] = max(ans[depth], node->val);
            }
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };
        dfs(root, 0);
        return ans;
    }
};
