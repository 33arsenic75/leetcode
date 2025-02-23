class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int preIndex = 0;
        int postIndex = 0;
        return constructTree(preIndex, postIndex, preorder, postorder);
    }
private:
    TreeNode* constructTree(int& preIndex, int& postIndex, vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;  // Mark this node as created
        if (root->val != postorder[postIndex]) {
            root->left =
                constructTree(preIndex, postIndex, preorder, postorder);
        }
        if (root->val != postorder[postIndex]) {
            root->right =
                constructTree(preIndex, postIndex, preorder, postorder);
        }
        postIndex++;
        return root;
    }
};