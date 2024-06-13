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
    vector<int>data;
    bool left(TreeNode*root){
        TreeNode*temp = root;
        if(!temp->left)return true;
        temp=temp->left;
        while(temp->right)temp=temp->right;
        return (root->val) > (temp->val);
    }
    bool right(TreeNode*root){
        TreeNode*temp = root;
        if(!temp->right)return true;
        temp=temp->right;
        while(temp->left)temp=temp->left;
        return (root->val) < (temp->val);
    }
    void fill(TreeNode*root){
        if(!root)return;
        fill(root->left);
        data.push_back(root->val);
        fill(root->right);
    }
    bool isValidBST(TreeNode* root) {
        fill(root);
        for(int i = 0 ; i < data.size() - 1 ; i++){
            if(data[i+1]<=data[i])return false;
        }
        return true;
        // if(!root)return true;
        // return isValidBST(root->right) && isValidBST(root->left) && left(root) && right(root);
    }
};
