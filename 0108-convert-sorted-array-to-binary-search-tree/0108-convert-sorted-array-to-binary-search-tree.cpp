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
    TreeNode* sorted(vector<int>&nums,int i, int j){
        if(i>j)return nullptr;
        else if(i==j)return new TreeNode(nums[i]);
        int mid = i + (j-i)/2;
        TreeNode*n = new TreeNode(nums[mid]);
        n->left = sorted(nums,i,mid-1);
        n->right = sorted(nums,mid+1,j);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sorted(nums,0,n-1);
    }
};