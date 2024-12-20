
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;  // Flag to track odd levels
        while (!q.empty()) {
            int sz = (int)q.size();  // Number of nodes at the current level
            vector<TreeNode*> v;
            // Traverse the current level
            for (int i = 0; i < sz; i++) {
                if (q.front() == NULL) {
                    q.pop();
                    continue;
                }
                v.push_back(q.front());  // Collect nodes of this level
                q.push(q.front()->left);  // Add left child
                q.push(q.front()->right); // Add right child
                q.pop();  // Remove processed node
            }
            // Reverse the nodes at odd levels
            if (flag) {
                int L = 0, R = (int)v.size() - 1;
                while (L <= R) {
                    swap(v[L++]->val, v[R--]->val);  // Swap values
                }
            }
            flag = (!flag);  // Toggle flag for the next level
        }
        return root;
    }
};