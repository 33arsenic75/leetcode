class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

private:
    void preorder(Node* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        for (Node* child : root->children) {
            preorder(child, ans);
        }
    }
};