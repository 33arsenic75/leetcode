class Solution {
public:
    int f(TreeNode *curr){
        if(curr==nullptr) return 1e9;
        if(curr->left==nullptr and curr->right==nullptr) return 1;
        return 1 + min(f(curr->left),f(curr->right));
    }
    int minDepth(TreeNode* curr) {
        int ans = f(curr);
        return ans==1e9?0:ans;
    }
};