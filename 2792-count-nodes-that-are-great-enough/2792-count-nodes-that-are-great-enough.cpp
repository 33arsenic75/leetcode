class Solution {
public:
    using P = pair<int, multiset<int>>;

    P helper(TreeNode* root, int k) {
        if (!root) return {0, {}};

        auto p1 = helper(root->left, k);
        auto p2 = helper(root->right, k);

        int ans = p1.first + p2.first;

        if (p1.second.size() < p2.second.size()) swap(p1, p2);

        p1.second.insert(p2.second.begin(), p2.second.end());

        int count = 0;
        for (int num : p1.second) {
            if (num < root->val) count++;
            if (count >= k) break;
        }

        ans += (count >= k);

        p1.second.insert(root->val);

        while (p1.second.size() > k) {
            auto it = prev(p1.second.end());
            p1.second.erase(it);
        }

        return {ans, p1.second};
    }

    int countGreatEnoughNodes(TreeNode* root, int k) {
        return helper(root, k).first;
    }
};