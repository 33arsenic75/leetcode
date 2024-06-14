class Solution {
vector<string> res;
public:

    void helper(TreeNode* root,string s){
        if(!root){return;}
        if(s.empty()){s+=(to_string(root->val));}
        else{s=s+"->"+(to_string(root->val));}
        if(!root->left && !root->right){
            res.push_back(s);
        }
        helper(root->left,s);
        helper(root->right,s);
        // s.erase(s.end() - 3);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,"");
        return res;
    }
};