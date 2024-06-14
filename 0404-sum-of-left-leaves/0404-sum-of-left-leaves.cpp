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
    int sum(TreeNode*root, bool b){
        if(!root)return 0;
        else if(root->right || root->left)return sum(root->right,false) + sum(root->left,true);
        else if(b)return root->val;
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root,false);
    }
};