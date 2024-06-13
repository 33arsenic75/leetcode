class Solution {
public:
    vector<int> data;
    // Helper function to fill the data vector with the values of the BST in inorder traversal
    void fill(TreeNode* root) {
        if (!root) return;
        fill(root->left);
        data.push_back(root->val);
        fill(root->right);
    }
    // Helper function to fill the BST with values from the sorted data vector
    void fill(TreeNode* root, int& idx) {
        if (!root) return;
        fill(root->left, idx);
        root->val = data[idx++];
        fill(root->right, idx);
    }
    void recoverTree(TreeNode* root) {
        fill(root); // Fill the data vector with inorder traversal of the BST
        sort(data.begin(), data.end()); // Sort the data vector
        int idx = 0;
        fill(root, idx); // Fill the BST with values from the sorted data vector
    }
};