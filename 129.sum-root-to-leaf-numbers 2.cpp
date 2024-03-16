/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int res = solve(root,0);
        return res;
    }
    
    int solve(TreeNode* root,int sum){
        if (root==NULL){
            return 0;
        }
        sum = sum*10 + root->val;
        if (root->left == NULL && root->right == NULL){
            return sum;
        }
        return solve(root->left,sum) + solve(root->right,sum);
    }

};
// @lc code=end

