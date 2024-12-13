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
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0, value = root->val;
        function<void(TreeNode*,int)>f = [&](TreeNode*n,int d){
            if(!n)return;
            if(d>depth){
                depth = d;
                value = n->val;
            }
            f(n->left,d+1);
            f(n->right,d+1);
        };
        f(root,0);
        return value;
    }
};