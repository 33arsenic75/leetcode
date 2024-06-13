class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;  // Return false for an empty tree
        }

        // Check if the current node is a leaf and its value matches the remaining targetSum
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recursively check the left and right subtrees with the updated targetSum
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
