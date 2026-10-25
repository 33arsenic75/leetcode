class Solution {
public:
    int ans;
 
    int solve(TreeNode* root, int parent) {
        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left, root->val);
        int right = solve(root->right, root->val);

        ans = max(ans, left + right);
        return root->val == parent ? max(left, right) + 1 : 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        solve(root, -1);
        
        return ans;
    }
};