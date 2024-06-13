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
    int height(TreeNode*n){
        if(!n)return 0;
        else return 1 + max(height(n->right),height(n->left));
    }
    vector<vector<int>>ans;
    vector<vector<TreeNode*>>temp;
    int ht;
    void help(int i,bool f){
        if(i==ht)return;
        int sz = temp[i-1].size();
        if(f){
            for(int idx = sz-1; idx>=0 ; idx--){
                if(temp[i-1][idx]->left){
                    temp[i].push_back(temp[i-1][idx]->left);
                }
                if(temp[i-1][idx]->right){
                    temp[i].push_back(temp[i-1][idx]->right);
                }
            }
        }
        else{
            for(int idx = sz-1; idx>=0 ; idx--){
                if(temp[i-1][idx]->right){
                    temp[i].push_back(temp[i-1][idx]->right);
                }
                if(temp[i-1][idx]->left){
                    temp[i].push_back(temp[i-1][idx]->left);
                }
            }
        }
        help(i+1,!f);
    }
    void fill(int i){
        if(i==ht)return;
        for(TreeNode*n:temp[i]){
            ans[i].push_back(n->val);
        }
        fill(i+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ht = height(root);
        ans = vector<vector<int>>(ht);
        temp = vector<vector<TreeNode*>>(ht);
        if(!root)return ans;
        temp[0].push_back(root);
        help(1,false);
        fill(0);
        return ans;
    }
};