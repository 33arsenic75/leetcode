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
    void process(TreeNode*root,int&ans,int val){
        if(!root)return;
        if(root->val >= val){
            val = root->val;
            ans++;
        }
        process(root->right,ans,val);
        process(root->left,ans,val);
    }
    int goodNodes(TreeNode* root) {
        int ans=1;
        process(root->right,ans,root->val);
        process(root->left,ans,root->val);
        return ans;
    }
};