class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> freq;

        function<int(TreeNode*)> sum = [&](TreeNode* n) -> int {
            if (!n) return 0;

            int s = n->val + sum(n->left) + sum(n->right);
            freq[s]++;
            return s;
        };

        int total = sum(root);

        // Exclude the root itself.
        freq[total]--;

        if (total % 2 != 0) return false;

        return freq[total / 2] > 0;
    }
};