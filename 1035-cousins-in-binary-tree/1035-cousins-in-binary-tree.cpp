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
    map<int,int>dp;
    map<int,int>par;
    void fill(TreeNode*root, int p = -1, int h = 0){
        if(!root)return;
        dp[root->val] = h;
        par[root->val] = p;
        fill(root->right,root->val,h+1);
        fill(root->left,root->val,h+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        fill(root);
        if(dp[x]==dp[y] && par[x]!=par[y])return true;
        return false;
    }
};