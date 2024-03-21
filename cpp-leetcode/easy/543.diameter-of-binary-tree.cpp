/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
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
    pair<int, int> calculateDiameterAndHeight(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto leftData = calculateDiameterAndHeight(root->left);
        auto rightData = calculateDiameterAndHeight(root->right);
        int currentDiameter = max(leftData.second + rightData.second,max(leftData.first, rightData.first));
        int currentHeight = max(leftData.second, rightData.second) + 1;
        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return calculateDiameterAndHeight(root).first;
    }
};
// @lc code=end

