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

    int sum(TreeNode* n){
        if(!n)return 0;
        return n->val + sum(n->right) + sum(n->left);
    }

    int findTilt(TreeNode* root) {
        if(!root)return 0;
        return findTilt(root->right) + findTilt(root->left) + abs(sum(root->right)-sum(root->left));
    }
};