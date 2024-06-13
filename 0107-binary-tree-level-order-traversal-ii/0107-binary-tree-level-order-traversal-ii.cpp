class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {}; // Base case

        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q; // Queue to store nodes and their levels

        q.push({root, 0}); // Push root node with level 0

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            // If the current level doesn't have a corresponding vector in result, create it
            if (level == result.size())
                result.push_back({});

            // Add node value to its corresponding level
            result[level].push_back(node->val);

            // Enqueue left and right children with their levels
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        // Reverse the result vector to get bottom-up level order traversal
        reverse(result.begin(), result.end());

        return result;
    }
};

// Helper function to create a binary tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

