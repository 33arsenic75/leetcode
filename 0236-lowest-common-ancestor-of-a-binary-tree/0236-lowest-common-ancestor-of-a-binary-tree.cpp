/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode*root, TreeNode* p){
        if(root==p)return true;
        else if(!root)return false;
        return exists(root->right,p) || exists(root->left,p);
    }
    bool existpair(TreeNode*root, TreeNode* p, TreeNode*q){
        return exists(root,p) && exists(root,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(existpair(root->right,p,q))return lowestCommonAncestor(root->right,p,q);
        else if(existpair(root->left,p,q))return lowestCommonAncestor(root->left,p,q);
        return root;
    }     
};