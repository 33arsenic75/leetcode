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
    int maxidx(vector<int>&nums, int start, int end){
        int ans = start;
        for(int i = start ; i <= end ; i++){
            if(nums[i]>nums[ans]){
                ans = i;
            }
        }
        return ans;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end){
        if(end<start)return nullptr;
        int idx = maxidx(nums,start,end);
        TreeNode*ans = new TreeNode(nums[idx]);
        ans->left = constructMaximumBinaryTree(nums,start,idx-1);
        ans->right = constructMaximumBinaryTree(nums,idx+1,end);
        return ans;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums,0,nums.size()-1);
    }
};