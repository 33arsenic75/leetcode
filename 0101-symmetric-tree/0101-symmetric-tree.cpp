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
    bool check(TreeNode*l, TreeNode*r){
        if(!l && !r)return true;
        else if(!r || !l)return false;
        else if(l->val != r->val)return false;
        return check(l->left,r->right) && check(l->right,r->left);
    }
    queue<TreeNode*>l,r;
    bool isSymmetric(TreeNode* root) {
        /// return check(root->left, root->right);
        if (!root) return true;
        queue<TreeNode*> l, r;
        l.push(root->left);
        r.push(root->right);
        TreeNode *x, *y;
        while (!l.empty() && !r.empty()) {
            x = l.front(); l.pop();
            y = r.front(); r.pop();
            if (!x && !y) continue;
            else if (!x || !y) return false;
            else if (x->val != y->val) return false;
            l.push(x->left);
            r.push(y->right);
            l.push(x->right);
            r.push(y->left);
        }
        return true;
    }
};