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
    pair<int, int> robDP(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftRob, leftSkip] = robDP(root->left);
        auto [rightRob, rightSkip] = robDP(root->right);

        int rob = root->val + leftSkip + rightSkip;
        int skip = max(leftRob, leftSkip) + max(rightRob, rightSkip);

        return {rob, skip};
    }

    int rob(TreeNode* root) {
        auto [take, skip] = robDP(root);
        return max(take, skip);
    }
};