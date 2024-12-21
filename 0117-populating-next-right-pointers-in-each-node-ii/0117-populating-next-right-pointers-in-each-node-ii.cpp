/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        vector<Node*>a;
        a.push_back(root);
        while(!a.empty()){
            vector<Node*>nxt;
            int n = a.size();
            for(int i = 0 ; i < n-1 ; i++){
                a[i]->next = a[i+1];
                if(a[i]->left)nxt.push_back(a[i]->left);
                if(a[i]->right)nxt.push_back(a[i]->right);
            }
            a[n-1]->next = nullptr;
            if(a[n-1]->left)nxt.push_back(a[n-1]->left);
            if(a[n-1]->right)nxt.push_back(a[n-1]->right);
            a = nxt;
        }
        return root;
    }
};