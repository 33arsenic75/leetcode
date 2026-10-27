class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        int total = 0;

        function<int(TreeNode*)> sum = [&](TreeNode* n) -> int {
            if (!n) return 0;
            return n->val + sum(n->right) + sum(n->left);
        };

        total = sum(root);

        if (total % 2 != 0) return false;

        function<bool(TreeNode*)> check = [&](TreeNode* n) -> bool {
            if (!n) return false;

            int subtreeSum = n->val + sum(n->right) + sum(n->left);

            if (n != root && subtreeSum == total / 2)
                return true;

            return check(n->left) || check(n->right);
        };

        return check(root);
    }
};