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
    int check(TreeNode*root,int &ans){
        if(root==NULL) return 0;
        int a=check(root->left,ans);
        int b=check(root->right,ans);
        int c=a-b;
        if(c>1 or c<-1) ans=1000;
        return max(a+1,b+1);
    }
    bool isBalanced(TreeNode* root) {
        int ans=0;
        check(root,ans);
        return ans!=1000;
    }
};