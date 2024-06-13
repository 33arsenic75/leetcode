class Solution {
public:
    vector<vector<TreeNode*>> ans;

    TreeNode* copy(TreeNode* root, int offset) {
        if (!root) return nullptr;
        TreeNode* newNode = new TreeNode(root->val + offset);
        newNode->left = copy(root->left, offset);
        newNode->right = copy(root->right, offset);
        return newNode;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        ans = vector<vector<TreeNode*>>(n + 1);
        ans[0].push_back(nullptr);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (TreeNode* left : ans[j - 1]) {
                    for (TreeNode* right : ans[i - j]) {
                        TreeNode* root = new TreeNode(j);
                        root->left = copy(left, 0); // Offset the left subtree
                        root->right = copy(right, j); // Offset the right subtree
                        ans[i].push_back(root);
                    }
                }
            }
        }
        return ans[n];
    }
};
