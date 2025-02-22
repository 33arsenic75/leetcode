class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stack;
        int index = 0;
        int n = traversal.size();
        while (index < n) {
            int depth = 0;
            while (index < n && traversal[index] == '-') {
                depth++;
                index++;
            }
            int value = 0;
            while (index < n && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }
            TreeNode* node = new TreeNode(value);
            while (stack.size() > depth) {
                stack.pop();
            }
            if (!stack.empty()) {
                if (stack.top()->left == nullptr) {
                    stack.top()->left = node;
                } else {
                    stack.top()->right = node;
                }
            }
            stack.push(node);
        }
        while (stack.size() > 1) {
            stack.pop();
        }
        return stack.top();
    }
};