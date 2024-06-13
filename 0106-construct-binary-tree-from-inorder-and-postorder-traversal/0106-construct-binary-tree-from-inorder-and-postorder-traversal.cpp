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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return nullptr;
        else if(inorder.size()==1)return new TreeNode(inorder[0]);
        int i = 0, j = 0, n = inorder.size();
        int self = postorder[n-1];
        vector<int>t1,t2,t3,t4;
        while(inorder[i]!=self){
            t1.push_back(inorder[i]);
            t2.push_back(postorder[j]);
            i++;j++;
        }
        i++;
        while(i<n){
            t3.push_back(inorder[i]);
            t4.push_back(postorder[j]);
            i++;
            j++;
        }
        TreeNode*l = buildTree(t1,t2);
        TreeNode*r = buildTree(t3,t4);
        return new TreeNode(self,l,r);
    }
};
/// inorder ->left self right
/// postorder -> left right self