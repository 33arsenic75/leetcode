#include <stack>
#include <iostream>
using namespace std;

class BSTIterator {
public:
    TreeNode* n;
    stack<TreeNode*> stk;

    BSTIterator(TreeNode* root) {
        n = root;
        while (n) {
            stk.push(n);
            n = n->left;
        }
    }

    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        int val = temp->val;
        if (temp->right) {
            temp = temp->right;
            while (temp) {
                stk.push(temp);
                temp = temp->left;
            }
        }
        return val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};
