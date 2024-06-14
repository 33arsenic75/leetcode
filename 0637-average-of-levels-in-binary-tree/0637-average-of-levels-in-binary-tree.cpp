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
    int heights(TreeNode* root,int ans){
        if(!root)return ans;
        return max(heights(root->right,ans+1),heights(root->left,ans+1));
    }
    void fillheight(TreeNode* root,int depth, vector<double>&total,vector<double>&sum){
        if(!root)return;
        total[depth]++;
        sum[depth]+=root->val;
        fillheight(root->right,depth+1,total,sum);
        fillheight(root->left,depth+1,total,sum);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int depth=heights(root,0);
        vector<double>sum(depth,0);
        vector<double>total(depth,0);
        fillheight(root,0,total,sum);
        vector<double>ans(depth,0);
        for(int i=0;i<depth;i++){
            ans[i]=sum[i]/total[i];
        }
        return ans;
    }
};