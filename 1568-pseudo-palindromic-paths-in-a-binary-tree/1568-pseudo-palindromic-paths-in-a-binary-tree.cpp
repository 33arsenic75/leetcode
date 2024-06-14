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
    int ans;
    void check(int count){
        int o = __builtin_popcount(count);
        if(o<2)ans++;
    }
    void traversal(TreeNode*n,int count){
        count=count ^ (1<<(n->val));
        if(n->right)traversal(n->right,count);
        if(n->left)traversal(n->left,count);
        if(!n->right && !n->left)check(count);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        int count=0;
        traversal(root,count);
        return ans;
    }
};