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
    int ht(TreeNode*root){
        int height = -1;
        while(root){
            root = root->left;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int h = ht(root);
        int hr = 1+ht(root->right);
        if(hr==h){
            // cout<<root->val<<' '<<h<<" right\n";
            return (1<<h) + countNodes(root->right);
        }
        // cout<<root->val<<' '<<h<<" left\n";
        return (1<<(h-1)) + countNodes(root->left);
    }
};