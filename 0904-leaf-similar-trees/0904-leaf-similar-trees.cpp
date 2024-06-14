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
    vector<int>t1,t2;
    void help1(TreeNode*n){
        if(!n)return;
        else if(!(n->right) && !(n->left)){
            t1.push_back(n->val);
            return;
        }
        help1(n->left);
        help1(n->right);
    }
    void help2(TreeNode*n){
        if(!n)return;
        else if(!(n->right) && !(n->left)){
            t2.push_back(n->val);
            return;
        }
        help2(n->left);
        help2(n->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        help1(root1);
        help2(root2);
        if(t1.size()!=t2.size())return false;
        for(int i = 0 ; i < t1.size() ; i++){
            if(t1[i]!=t2[i])return false;
        }
        return true;
    }
};