class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        connect(root->left);
        connect(root->right);
        Node*l,*r;
        l = root->left;
        r = root->right;
        while(l){
            l->next = r;
            l = l->right;
            r = r->left;
        }
        return root;
    }
};