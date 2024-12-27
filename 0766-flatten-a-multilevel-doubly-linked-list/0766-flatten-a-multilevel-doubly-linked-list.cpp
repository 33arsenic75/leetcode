class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)return nullptr;
        if(head->child){
            Node* x = flatten(head->child);
            Node* n = head->next;
            head->next = x;
            x->prev = head;
            while(x->next)x = x->next;
            x->next = flatten(n);
            if(n)n->prev = x;
            head->child = nullptr;
            return head;
        }
        else{
            Node*n = flatten(head->next);
            head->next = n;
            if(n)n->prev = head;
            return head;
        }
    }
};