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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        else if(!p)return false;
        else if(!q)return false;
        else if(p->val != q->val)return false;
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)return true;
        else if(!root)return false;
        else if(isSameTree(root,subRoot))return true;
        return isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);

    }
};