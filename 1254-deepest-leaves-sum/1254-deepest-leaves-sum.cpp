class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        function<void(TreeNode*, int)> dd = [&](TreeNode* r, int d) {
            if (!r) return;
            depth = max(depth, d);
            dd(r->right, d + 1);
            dd(r->left, d + 1);
        };
        
        int sum = 0;
        function<void(TreeNode*, int)> ss = [&](TreeNode* r, int d) {
            if (!r) return;
            if (d == depth) sum += r->val;
            ss(r->right, d + 1);
            ss(r->left, d + 1);
        };
        
        dd(root, 0);
        ss(root, 0);
        return sum;
    }
};
