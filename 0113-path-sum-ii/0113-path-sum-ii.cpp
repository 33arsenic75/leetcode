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
    bool isleaf(TreeNode*n){
        return !(n->right) && !(n->left);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return vector<vector<int>>();
        else if(isleaf(root) && root->val == targetSum)return vector<vector<int>>{{root->val}};
        vector<vector<int>>t1,t2,ans;
        if(root->right){
            t1 = pathSum(root->right,targetSum - root->val);
            for(vector<int>&x:t1){
                x.insert(x.begin(),root->val);
                ans.push_back(x);
            }
        }
        if(root->left){
            t2 = pathSum(root->left,targetSum - root->val);
            for(vector<int>&x:t2){
                x.insert(x.begin(),root->val);
                ans.push_back(x);
            }
        }
        return ans;
    }
};