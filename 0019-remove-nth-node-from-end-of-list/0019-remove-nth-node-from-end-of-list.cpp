/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void size(ListNode* head, int& sz) {
        if (!head) return;
        sz++;
        size(head->next, sz);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        size(head,sz);
        if(n==sz)return head->next;
        else{
            /// 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8
        }
        int i=1;
        ListNode*node=head;
        while(i<sz-n){
            i++;
            node=node->next;
        }
        node->next = node->next->next;
        return head;
    }
};