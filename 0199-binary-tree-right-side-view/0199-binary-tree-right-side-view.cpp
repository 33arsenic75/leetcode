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
    int depth(TreeNode*root){
        if(!root)return 0;
        return 1+max(depth(root->right),depth(root->left));
    }
    void fill(TreeNode*n,int index,vector<int>&ans){
        if(!n)return;
        else if(ans[index]==101){
            ans[index]=n->val;
        }
        fill(n->right,index+1,ans);
        fill(n->left,index+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(depth(root),101);
        fill(root,0,ans);
        return ans;
    }
};