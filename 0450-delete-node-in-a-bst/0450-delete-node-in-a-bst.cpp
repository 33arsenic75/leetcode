class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            if (root->right) {
                TreeNode* cur = root->right;
                while (cur->left) cur = cur->left;

                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
            else if (root->left) {
                TreeNode* cur = root->left;
                while (cur->right) cur = cur->right;

                root->val = cur->val;
                root->left = deleteNode(root->left, cur->val);
            }
            else {
                delete root;
                return nullptr;
            }
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};