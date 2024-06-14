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
    int ans=0;
    int sumgp(TreeNode*root){
        if(root==nullptr)return 0;
        else if(root->val%2!=0)return 0;
        ///cout<<root->val<<' ';
        return sump(root->right)+sump(root->left);
    }
    int sump(TreeNode*root){
        if(root==nullptr)return 0;
        return sum(root->right)+sum(root->left);
    }
    int sum(TreeNode*root){
        if(root==nullptr)return 0;
        cout<<root->val<<' ';
        return root->val;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return pr(root);
    }
    int pr(TreeNode*root){
        if(root==nullptr)return 0;
        return sumgp(root)+pr(root->right)+pr(root->left);
    }
};