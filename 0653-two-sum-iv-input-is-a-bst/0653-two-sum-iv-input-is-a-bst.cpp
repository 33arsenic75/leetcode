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
    vector<int>temp;
    void visit(TreeNode*root){
        if(!root)return;
        visit(root->left);
        temp.push_back(root->val);
        visit(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        visit(root);
        int i = 0, j = temp.size() - 1;
        int sum;
        while(i < j){
            sum = temp[i] + temp[j];
            if(sum==k)return true;
            else if(sum < k)i++;
            else if(sum > k)j--;
        }
        return false;
    }
};