/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isleaf(TreeNode*n){
        return !(n->right) && !(n->left);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return nullptr;
        root->right = removeLeafNodes(root->right,target);
        root->left = removeLeafNodes(root->left,target);
        if(isleaf(root) && root->val == target){
            return nullptr;
        }
        else return root;
    }
};