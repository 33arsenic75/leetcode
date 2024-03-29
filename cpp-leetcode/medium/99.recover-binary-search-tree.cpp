/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
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
    void recoverTree(TreeNode* root) {
        if(!root)return;
        else if(root->right && root->right->val < root->val){
            swap(root->right->val,root->val);
            return;
        }
        else if(root->left && root->left->val > root->val){
            swap(root->left->val,root->val);
            return;
        }
        recoverTree(root->right);recoverTree(root->left);
    }
};
// @lc code=end

