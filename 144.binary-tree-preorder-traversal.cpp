/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int>ans;
    void recursive(TreeNode* root){
        if(!root)return;
        ans.push_back(root->val);
        recursive(root->left);
        recursive(root->right);
    }
    void iterative(TreeNode * root){
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            stk.pop();
            ans.push_back(temp->val);
            if(temp->right)stk.push(temp->right);
            if(temp->left)stk.push(temp->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        ans = vector<int>();
        ///recursive(root);
        if(root)iterative(root);
        return ans;
    }
};
// @lc code=end

